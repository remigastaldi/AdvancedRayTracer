#include "Line.hpp"
#include "Transform2D.hpp"
#include "Brush.hpp"
#include "Pen.hpp"

#include <QPainter>

// #include <vector>

namespace ART {
namespace Logic {

Line::Line(std::string id) : Shape2D{std::move(id)} {
  auto *pen = new Modules::Pen(*this, "Pen");
  connect(pen, &Modules::Pen::dataUpdate, this, &Line::dataUpdate);
}

void Line::draw(QPainter *painter) noexcept {
  auto &pen = getChildren<Modules::Pen>("Pen");
  pen.get().setWidth(10);
  painter->setPen(pen.get());
  auto &trans = getChildren<Modules::Transform2D>("Transform2D");
  _line = QLineF(trans.x(), trans.y(), trans.x() + trans.width(), trans.y() + trans.height());
  painter->drawLine(_line);
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