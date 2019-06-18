#pragma once

#include "globals.h"

#include "Entity.hpp"
#include "Shape2D.hpp"

#include <QPainterPath>

#include <QObject>

namespace ART {
namespace Logic {
class Scene2D;
class Shape2D;

namespace Modules {

class ADVANCED_RAY_TRACER_EXPORT Transform2D : public Entity {
  Q_OBJECT
  Q_PROPERTY(int x READ x NOTIFY dataUpdate)
  Q_PROPERTY(int y READ y NOTIFY dataUpdate)
  Q_PROPERTY(int width READ width NOTIFY dataUpdate)
  Q_PROPERTY(int height READ height NOTIFY dataUpdate)
  Q_PROPERTY(int angle READ angle NOTIFY dataUpdate)

public:
  Transform2D(Shape2D &parent, std::string id);

  double x() const noexcept;
  double y() const noexcept;
  double width() const noexcept;
  double height() const noexcept;
  int angle() const noexcept;

public Q_SLOTS:
  void setX(double x) noexcept;
  void setY(double y) noexcept;
  void setWidth(double width) noexcept;
  void setHeight(double height) noexcept;
  void setAngle(int angle) noexcept;

  virtual void move(double x, double y) noexcept;
  virtual void scale(double x, double y) noexcept;
  virtual std::vector<QPointF> getPoints() const noexcept;

Q_SIGNALS:
  void dataUpdate();

private:
  double _x;
  double _y;
  double _width;
  double _height;
  int _angle;
};

} // namespace Modules
} // namespace Logic
} // namespace ART