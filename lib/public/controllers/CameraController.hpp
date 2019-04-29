#pragma once

#include "globals.h"

#include <QCamera>
#include <QObject>
#include <QPointer>
#include <QString>
#include <QVector3D>

namespace ART::Controllers {

class ADVANCED_RAY_TRACER_EXPORT CameraController : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(CameraController)
  DISABLE_MOVE(CameraController)

public:
  explicit CameraController(QObject* parent = nullptr) : QObject{parent}, _camera{nullptr} {}
  ~CameraController() override = default;

  [[nodiscard]] Qt3DRender::QCamera *model() const noexcept {
    return _camera;
  }

public Q_SLOTS:
  void setModel(Qt3DRender::QCamera *camera) { _camera = camera; }

private:
  Qt3DRender::QCamera *_camera;
};

} // namespace ART::Controllers
