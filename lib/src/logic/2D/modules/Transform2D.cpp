#include "Transform2D.hpp"

#include "Entity.hpp"
#include "Scene2D.hpp"
#include "Shape2D.hpp"

namespace ART {
namespace Logic {
namespace Modules {

Transform2D::Transform2D(Shape2D &parent, std::string id) : Entity{std::move(id)}, _x{0}, _y{0}, _width{0}, _height{0}, _angle{0} {
  parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
}

double Transform2D::x() const noexcept { return _x; }
double Transform2D::y() const noexcept { return _y; }
double Transform2D::width() const noexcept { return _width; }
double Transform2D::height() const noexcept { return _height; }
int Transform2D::angle() const noexcept { return _angle; }

void Transform2D::setX(double x) noexcept {
  _x = x;
  Q_EMIT dataUpdate();
}

void Transform2D::setY(double y) noexcept {
  _y = y;
  Q_EMIT dataUpdate();
}

void Transform2D::setWidth(double width) noexcept {
  _width = width;
  Q_EMIT dataUpdate();
}

void Transform2D::setHeight(double height) noexcept {
  _height = height;
  Q_EMIT dataUpdate();
}

void Transform2D::setAngle(int angle) noexcept {
	_angle = angle;
	Q_EMIT dataUpdate();
}

void Transform2D::move(double x, double y) noexcept {
  _x = x;
  _y = y;
  Q_EMIT dataUpdate();
};

void Transform2D::scale(double x, double y) noexcept {
  _width += x;
  _height += y;
  Q_EMIT dataUpdate();
}

std::vector<QPointF> Transform2D::getPoints() const noexcept { return {{_x, _y}, {_width, _height}}; }

} // namespace Modules
} // namespace Logic
} // namespace ART