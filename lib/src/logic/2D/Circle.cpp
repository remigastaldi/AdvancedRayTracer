#include "Circle.hpp"

#include <QPainter>

namespace ART {
namespace Logic {

Circle::Circle(std::string id) : Shape2D{std::move(id)} {}

void Circle::draw(QPainter *painter) noexcept {
  painter->setBrush(Qt::blue);
  painter->drawEllipse(x1, y1, x2, y2);
}

} // namespace Logic
} // namespace ART