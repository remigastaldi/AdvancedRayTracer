#include "FbItemRenderer.hpp"
#include "FbItem.hpp"

namespace ART {
namespace Logic {

FbItemRenderer::FbItemRenderer() : _program{nullptr} {
  initializeOpenGLFunctions();

  _program = std::make_unique<QOpenGLShaderProgram>();
  _program->addCacheableShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/test.vert");
  _program->addCacheableShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/test.frag");

  _program->bindAttributeLocation("vertices", 0);
  _program->link();
}

QOpenGLFramebufferObject *FbItemRenderer::createFramebufferObject(const QSize &size) {
  QOpenGLFramebufferObjectFormat format;
  format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
  format.setSamples(4);

  return new QOpenGLFramebufferObject(size, format);
}

void FbItemRenderer::render() noexcept {
  qInfo() << "Start rendering";

  _program->bind();

  _program->enableAttributeArray(0);

  float values[] = {-1, -1, 1, -1, -1, 1, 1, 1};
  _program->setAttributeArray(0, GL_FLOAT, values, 2);
  _program->setUniformValue("t", 0);

  // glViewport(0, 0, 800, 600);

  glDisable(GL_DEPTH_TEST);

  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE);

  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  _program->disableAttributeArray(0);
  _program->release();

  _window->resetOpenGLState();
}

void FbItemRenderer::synchronize(QQuickFramebufferObject *qqfbo) noexcept {
  qInfo() << "Synchronize data before rendering";

  auto parentItem = dynamic_cast<Logic::FbItem *>(qqfbo);
  _window = parentItem->window();
  _fbItem = parentItem;
}

} // namespace Models
} // namespace ART
