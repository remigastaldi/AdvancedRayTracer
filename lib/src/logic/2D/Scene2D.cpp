#include "Scene2D.hpp"
#include <QPainter>

namespace ART {
namespace Logic {

Scene2D::Scene2D() {}

void Scene2D::paint(QPainter *painter) {
  qInfo() << "===============";
  painter->setBrush(Qt::blue);
  painter->drawRect(0, 0, 400, 400);
}

} // namespace Logic
} // namespace ART