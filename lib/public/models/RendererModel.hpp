#pragma once

#include <iostream>
#include <memory>

#include <QObject>
#include <QOpenGLShaderProgram>
#include <QPointer>
#include <QString>
#include <QtGui/QOpenGLFramebufferObject>
#include <QtOpenGL/qglfunctions.h>
#include <QtQuick/QQuickFramebufferObject>
#include <QtQuick/QQuickWindow>
#include <QtQuick/qquickwindow.h>
#include <QOpenGLPaintDevice>

#include "globals.h"

namespace ART {
namespace Logic {
} // nameSpace Logic
namespace Controllers {
  class RendererController;
} // namesSpace Controller
namespace Models {

class ADVANCED_RAY_TRACER_EXPORT RendererModel : public QQuickItem,
                                                 public QQuickFramebufferObject::Renderer,
                                                 protected QOpenGLFunctions
{
  Q_OBJECT
public:
  RendererModel();
  
  void render() noexcept override;

private:
  std::unique_ptr<QOpenGLShaderProgram> _program;
  QQuickWindow *_window;
  Controllers::RendererController *_controller;

protected:
  QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;
  void synchronize(QQuickFramebufferObject *item) noexcept override;
};

} // namespace Models
} // namespace ART
