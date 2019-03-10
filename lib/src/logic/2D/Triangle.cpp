#include "Triangle.hpp"
#include "Brush.hpp"
#include "Pen.hpp"
#include "Transform2D.hpp"

#include <QPainter>

namespace ART {
namespace Logic {

Triangle::Triangle(std::string id) : Shape2D{std::move(id)} {
  auto *brush = new Modules::Brush(*this, "Brush");
  connect(brush, &Modules::Brush::dataUpdate, this, &Triangle::dataUpdate);
  auto *pen = new Modules::Pen(*this, "Pen");
  connect(pen, &Modules::Pen::dataUpdate, this, &Triangle::dataUpdate);
  new Modules::Pen(*this, "Pen");
}

void Triangle::draw(QPainter *painter) noexcept {
  _path = QPainterPath();
  auto &brush = getChildren<Modules::Brush>("Brush");
  painter->setBrush(brush.get());
  auto &pen = getChildren<Modules::Pen>("Pen");
  painter->setPen(pen.get());
  auto &trans = getChildren<Modules::Transform2D>("Transform2D");  
  QRectF rect = QRectF(trans.x(), trans.y(), trans.width(), trans.height());

  _path.moveTo(rect.left() + (rect.width() / 2), rect.top());
  _path.lineTo(rect.bottomLeft());
  _path.lineTo(rect.bottomRight());
  _path.lineTo(rect.left() + (rect.width() / 2), rect.top());

  painter->drawPath(_path);
}

bool Triangle::contains(int x, int y) const noexcept {
  return _path.contains(QPointF(x, y));
}

} // namespace Logic
} // namespace ART