#include "Triangle.hpp"
#include "Transform2D.hpp"

#include <QPainter>

namespace ART {
namespace Logic {

Triangle::Triangle(std::string id) : Shape2D{std::move(id)} {}

void Triangle::draw(QPainter *painter) noexcept {
  _path = QPainterPath();
	auto &trans = getChildren<Modules::Transform2D>("Transform2D");  
  QRectF rect = QRectF(trans.x(), trans.y(), trans.width(), trans.height());

  _path.moveTo(rect.left() + (rect.width() / 2), rect.top());
  _path.lineTo(rect.bottomLeft());
  _path.lineTo(rect.bottomRight());
  _path.lineTo(rect.left() + (rect.width() / 2), rect.top());

  painter->setBrush(Qt::blue);
  painter->drawPath(_path);
}

bool Triangle::contains(int x, int y) const noexcept {
  return _path.contains(QPointF(x, y));
}

} // namespace Logic
} // namespace ART