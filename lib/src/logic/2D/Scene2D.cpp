#include "Scene2D.hpp"
#include "Rectangle.hpp"

#include <QPainter>

namespace ART {
namespace Logic {

Scene2D::Scene2D() {}

void Scene2D::paint(QPainter *painter) {
  for (auto & [ key, value ] : _entities) {
    value->draw(painter);
  }
}

void Scene2D::createRectangle() noexcept {
  std::unique_ptr<Rectangle> rect = std::make_unique<Rectangle>();
  _entities.emplace("Rectangle [0]", std::move(rect));
  QQuickPaintedItem::update();
}

} // namespace Logic
} // namespace ART