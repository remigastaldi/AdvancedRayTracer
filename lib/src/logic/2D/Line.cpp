#include "Line.hpp"
#include "Transform2D.hpp"

#include <QPainter>

// #include <vector>

namespace ART {
namespace Logic {

Line::Line(std::string id) : Shape2D{std::move(id)} {}

void Line::draw(QPainter *painter) noexcept {
	auto &trans = getChildren<Modules::Transform2D>("Transform");
  _line = QLineF(trans.x(), trans.y(), trans.x() + trans.width(), trans.y() + trans.height());
  painter->setPen(QPen{Qt::blue, 10});
  painter->drawLine(_line);
  painter->setPen(QPen{Qt::blue, 1});
}

bool Line::contains(int x, int y) const noexcept {
  QLineF perpendicLine(QPoint(x, y), QPointF(x, 0.0));
  perpendicLine.setAngle(90.0 + _line.angle());
  QPointF result;
  _line.intersect(perpendicLine, &result);

  if (abs(x - result.x()) <= 5 && abs(y - result.y()) <= 5) {
    return true;
  }
  return false;
}

} // namespace Logic
} // namespace ART