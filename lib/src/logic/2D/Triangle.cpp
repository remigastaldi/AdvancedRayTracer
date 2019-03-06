#include "Triangle.hpp"

#include <QPainter>

namespace ART {
namespace Logic {

  Triangle::Triangle(std::string id) : Shape2D{std::move(id)} {}

void Triangle::draw(QPainter *painter) noexcept {
  QRectF rect = QRectF(x1, y1, x2, y2);

  QPainterPath path;
  path.moveTo(rect.left() + (rect.width() / 2), rect.top());
  path.lineTo(rect.bottomLeft());
  path.lineTo(rect.bottomRight());
  path.lineTo(rect.left() + (rect.width() / 2), rect.top());

  shapeRect = path;

  painter->fillPath(path, QBrush(QColor("blue")));
}

} // namespace Logic
} // namespace ART