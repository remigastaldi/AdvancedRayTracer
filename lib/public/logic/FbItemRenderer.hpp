#pragma once

#include <memory>

#include <QObject>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPointer>
#include <QString>
#include <QtGui/QOpenGLFramebufferObject>
#include <QtOpenGL/qglfunctions.h>
#include <QtQuick/QQuickFramebufferObject>
#include <QtQuick/QQuickWindow>
#include <QtQuick/qquickwindow.h>

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

  void render() noexcept override;

private:
  std::unique_ptr<QOpenGLShaderProgram> _program;
  QQuickWindow *_window;
  Logic::FbItem *_fbItem;

protected:
  QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;
  void synchronize(QQuickFramebufferObject *item) noexcept override;
};

} // nameSpace Logic
} // namespace ART
