#include "Circle.hpp"
#include "Transform2D.hpp"

#include <QPainter>

namespace ART {
namespace Logic {

Circle::Circle(std::string id) : Shape2D{std::move(id)} {}

void Circle::draw(QPainter *painter) noexcept {
  _path = QPainterPath();

  painter->setBrush(Qt::blue);
	auto &trans = getChildren<Modules::Transform2D>("Transform");  
  _path.addEllipse(trans.x(), trans.y(), trans.width(), trans.height());
  painter->drawPath(_path);
}

bool Circle::contains(int x, int y) const noexcept {
  return _path.contains(QPoint(x, y));
}

} // namespace Logic
} // namespace ART