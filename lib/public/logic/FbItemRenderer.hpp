#pragma once

#include <memory>

#include <QObject>
#include <QOpenGLBuffer>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QPointer>
#include <QString>
#include <QtGui/QOpenGLFramebufferObject>
#include <QtOpenGL/qglfunctions.h>
#include <QtQuick/QQuickFramebufferObject>
#include <QtQuick/QQuickWindow>
#include <QtQuick/qquickwindow.h>

#include "Cube.hpp"
#include "Transform3D.hpp"

#include "globals.h"

namespace ART {

namespace Logic {

class FbItem;

class ADVANCED_RAY_TRACER_EXPORT FbItemRenderer : public QQuickItem,
                                                  public QQuickFramebufferObject::Renderer,
                                                  protected QOpenGLFunctions {
  Q_OBJECT

public:
  FbItemRenderer();
  virtual ~FbItemRenderer() noexcept;

  FbItemRenderer(const FbItemRenderer &other) = delete;
  FbItemRenderer(FbItemRenderer &&other) = delete;
  FbItemRenderer &operator=(const FbItemRenderer &other) = delete;
  FbItemRenderer &operator=(FbItemRenderer &&other) = delete;

protected:
  QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;
  void synchronize(QQuickFramebufferObject *item) noexcept override;
  void checkAutoRender() noexcept;
  void render() noexcept override;

private:
  QQuickWindow *_window;
  Logic::FbItem *_fbItem;

  QMatrix4x4 m_projection;

  std::chrono::high_resolution_clock::time_point t1;
  int _renderFps;

  std::unordered_map<size_t, std::unique_ptr<RenderObject>> _shapes;
};

} // nameSpace Logic
} // namespace ART
