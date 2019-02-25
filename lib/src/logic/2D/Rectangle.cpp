#include "Rectangle.hpp"

#include <QPainter>

namespace ART {
namespace Logic {

Rectangle::Rectangle() {}

void Rectangle::draw(QPainter *painter) noexcept {
  painter->setBrush(Qt::blue);
  painter->drawRect(0, 0, 400, 400);
}

} // namespace Logic
} // namespace ART