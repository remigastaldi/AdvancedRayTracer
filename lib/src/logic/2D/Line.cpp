#include "Line.hpp"

#include <QPainter>

namespace ART {
namespace Logic {

Line::Line(std::string id) : Shape2D{std::move(id)} {}

void Line::draw(QPainter *painter) noexcept {
  painter->setPen(Qt::blue);
  line = QLine(x1, y1, x2, y2);
  painter->drawLine(line);
}

} // namespace Logic
} // namespace ART