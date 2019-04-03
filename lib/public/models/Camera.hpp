#pragma once

#include "globals.h"

#include <QObject>
#include <QPointer>
#include <QString>
#include <QVector3D>

namespace ART::Models {

class ADVANCED_RAY_TRACER_EXPORT Camera : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(Camera)
  DISABLE_MOVE(Camera)

  Q_PROPERTY(QVector3D position MEMBER _pos NOTIFY positionChanged)

public:
  Camera() : _pos{0, 0, -30} {}
  ~Camera() override = default;

  const QVector3D &position() noexcept { return _pos; }

  void setPosition(const QVector3D & pos) {
    _pos = pos;
    Q_EMIT positionChanged();
  }

Q_SIGNALS:
  void positionChanged();

private:
  QVector3D _pos;
};

} // namespace ART::Models
