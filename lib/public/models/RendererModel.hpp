#pragma once

#include <memory>
#include <iostream>

#include <QString>
#include <QObject>
#include <QPointer>
#include <QtQuick/qquickwindow.h>
#include <QtOpenGL/qglfunctions.h>
#include <QOpenGLShaderProgram>
#include <QtGui/QOpenGLFramebufferObject>
#include <QtQuick/QQuickWindow>
#include <QtQuick/QQuickFramebufferObject>

#include "globals.h"

namespace ART {
  namespace Logic {
} // nameSpace Logic
namespace Models {

class ADVANCED_RAY_TRACER_EXPORT RendererModel : public QQuickItem, public QQuickFramebufferObject::Renderer, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    RendererModel();

QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;
void render() noexcept override;

public slots:

private:
    std::unique_ptr<QOpenGLShaderProgram> _program;
    QQuickWindow* _window;

protected:
    // void synchronize(QQuickFramebufferObject* qqfbo) override {
    //     RendererModel* parentItem = (RendererModel*)qqfbo;

    //     // m_window = parentItem->window();
    // }
};

} // namespace Models
} // namespace ART
