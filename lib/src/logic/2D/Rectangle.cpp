#include "Rectangle.hpp"
#include "Transform2D.hpp"
#include <QPainter>

namespace ART {
namespace Logic {

Rectangle::Rectangle(std::string id) : Shape2D{std::move(id)} {
}

void Rectangle::draw(QPainter *painter) noexcept {
  _path = QPainterPath();
	auto &trans = getChildren<Modules::Transform2D>("Transform");  
  _path.addRect(trans.x(), trans.y(), trans.width(), trans.height());

  painter->setBrush(Qt::blue);
  painter->drawPath(_path);
}

bool Rectangle::contains(int x, int y) const noexcept { return _path.contains(QPointF(x, y)); }

} // namespace Logic
} // namespace ART