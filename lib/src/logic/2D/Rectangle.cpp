#include "Rectangle.hpp"

#include <QPainter>

namespace ART {
namespace Logic {

Rectangle::Rectangle(std::string id) : Shape2D{std::move(id)} {}

void Rectangle::draw(QPainter *painter) noexcept {
  painter->setBrush(Qt::blue);
  painter->drawRect(0, 0, 400, 400);
}

} // namespace Logic
} // namespace ART