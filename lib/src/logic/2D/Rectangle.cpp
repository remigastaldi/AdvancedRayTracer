#include "Rectangle.hpp"
#include "Transform2D.hpp"
#include "Brush.hpp"
#include "Pen.hpp"
#include <QPainter>

namespace ART {
namespace Logic {

Rectangle::Rectangle(std::string id) : Shape2D{std::move(id)} {
  auto *brush = new Modules::Brush(*this, "Brush");
  connect(brush, &Modules::Brush::dataUpdate, this, &Rectangle::dataUpdate);
  auto *pen = new Modules::Pen(*this, "Pen");
  connect(pen, &Modules::Pen::dataUpdate, this, &Rectangle::dataUpdate);
}

void Rectangle::draw(QPainter *painter) noexcept {
  _path = QPainterPath();
  auto &brush = getChildren<Modules::Brush>("Brush");
  painter->setBrush(brush.get());
  auto &pen = getChildren<Modules::Pen>("Pen");
  painter->setPen(pen.get());
  auto &trans = getChildren<Modules::Transform2D>("Transform2D");  
  _path.addRect(trans.x(), trans.y(), trans.width(), trans.height());
  painter->drawPath(_path);
}

bool Rectangle::contains(int x, int y) const noexcept { return _path.contains(QPointF(x, y)); }

} // namespace Logic
} // namespace ART