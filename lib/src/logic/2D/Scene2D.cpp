#include "Scene2D.hpp"
#include <QPainter>

namespace ART {
namespace Logic {

Scene2D::Scene2D() {}

void Scene2D::paint(QPainter *painter) {
  painter->setBrush(Qt::blue);
  painter->drawRect(0, 0, 400, 400);
}

void Scene2D::createRectangle() noexcept {
  // Todo, create an hashmap like for 3d with 2d shapes, add rectangle and call update
}

} // namespace Logic
} // namespace ART