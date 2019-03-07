#include "PaintedItem.hpp"
#include "Scene2D.hpp"

#include <iostream>

namespace ART {
namespace Logic {

void PaintedItem::paint(QPainter *painter) {
  // Q_EMIT paintEvent(painter);
  if (_scene2D != nullptr) {
    _scene2D->paint(painter);
  }
}

void PaintedItem::setScene2D(Scene2D *scene2D) {
  _scene2D = scene2D;
}

} // namespace Logic
} // namespace ART