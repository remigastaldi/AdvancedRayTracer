#include "Circle.hpp"
#include "Brush.hpp"
#include "Pen.hpp"
#include "Transform2D.hpp"

#include <QPainter>

namespace ART {
namespace Logic {

Circle::Circle(std::string id) : Shape2D{std::move(id)} {
  auto *brush = new Modules::Brush(*this, "Brush");
  connect(brush, &Modules::Brush::dataUpdate, this, &Circle::dataUpdate);
  auto *pen = new Modules::Pen(*this, "Pen");
  connect(pen, &Modules::Pen::dataUpdate, this, &Circle::dataUpdate);
  new Modules::Pen(*this, "Pen");
}

void Circle::draw(QPainter *painter) noexcept {
  _path = QPainterPath();
  auto &brush = getChildren<Modules::Brush>("Brush");
  painter->setBrush(brush.get());
  auto &pen = getChildren<Modules::Pen>("Pen");
  painter->setPen(pen.get());
  auto &trans = getChildren<Modules::Transform2D>("Transform2D");
  QRectF ellipse(trans.x(), trans.y(), trans.width(), trans.height());
  QPoint center(ellipse.center().x(), ellipse.center().y());
  QTransform t = QTransform().translate(center.x(), center.y()).rotate(trans.angle()).translate(-center.x(), -center.y());
  QRectF rotatedRect = t.mapRect(ellipse);
  _path.addPolygon(ellipse);
  painter->drawEllipse(rotatedRect);
}

bool Circle::contains(int x, int y) const noexcept { return _path.contains(QPoint(x, y)); }

} // namespace Logic
} // namespace ART