#include "FbItemRenderer.hpp"
#include "FbItem.hpp"

#include <chrono>
#include <thread>
#include <iostream>

namespace ART {
namespace Logic {

FbItemRenderer::FbItemRenderer() :  _renderFps{60} {
  qInfo() << "Creating FbItemRenderer";

  initializeOpenGLFunctions();


  glEnable(GL_CULL_FACE);
}

FbItemRenderer::~FbItemRenderer() noexcept {
}


QOpenGLFramebufferObject *FbItemRenderer::createFramebufferObject(const QSize &size) {
  QOpenGLFramebufferObjectFormat format;
  format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
  format.setSamples(4);

  return new QOpenGLFramebufferObject(size, format);
}

void FbItemRenderer::render() noexcept {
  qInfo() << "Start rendering";
  
  m_projection.setToIdentity();
  m_projection.perspective(45.0f, _fbItem->width() / _fbItem->height(), 0.0f, 1000.0f);
  // glViewport(0, 0, _fbItem->width(), _fbItem->height());
  glDisable(GL_DEPTH_TEST);

  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE);

  for (auto &shape : _shapes) {
    auto transform = dynamic_cast<Transform3D*>(shape.second.get());
    transform->rotate(1.0f, QVector3D(0.4f, 0.3f, 0.3f));

    shape.second->update(m_projection);
  }

  _window->resetOpenGLState();

  if (_renderFps > 0) {
    checkAutoRender();
  }
  qInfo() << "End rendering";
}

void  FbItemRenderer::checkAutoRender() noexcept {
  auto t2 = std::chrono::high_resolution_clock::now();
  auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

  if (int_ms.count() < 1000 / _renderFps) {
    // std::cout << "sleep for " << 16 - static_cast<int>(int_ms.count()) << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000 / _renderFps - static_cast<int>(int_ms.count())));
  }
  t1 = std::chrono::high_resolution_clock::now();
  // synchronize(_fbItem);
  Renderer::update();
}

void  FbItemRenderer::synchronize(QQuickFramebufferObject *qqfbo) noexcept {
  qInfo() << "Synchronize data before rendering";
  
  auto parentItem = dynamic_cast<Logic::FbItem *>(qqfbo);
  _window = parentItem->window();
  _fbItem = parentItem;

  _shapes.clear();
  for (const auto &shape : parentItem->shapes()) {
    switch (shape.second.type) {
      case FbItem::Type::CUBE:
        _shapes.emplace(shape.first, std::make_unique<Cube>(shape.second.transform));
      break;
    }
  }

  t1 = std::chrono::high_resolution_clock::now();
}

} // namespace Logic
} // namespace ART