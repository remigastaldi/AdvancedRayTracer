#include "PaintedItem.hpp"
#include "Scene2D.hpp"

#include <iostream>

namespace ART {
namespace Logic {

PaintedItem::PaintedItem() {
  QQuickItem::setAntialiasing(true);
}

void PaintedItem::paint(QPainter *painter) {
  Q_EMIT paintUpdate(painter);
}

void PaintedItem::mousePressEvent(QMouseEvent *event) {
  setFocus(true);
  Q_EMIT mousePressUpdate(event);
}

void PaintedItem::mouseMoveEvent(QMouseEvent *event) {
  Q_EMIT mouseMoveUpdate(event);
}

void PaintedItem::mouseReleaseEvent(QMouseEvent *event) {
  Q_EMIT mouseReleaseUpdate(event);
}

} // namespace Logic
} // namespace ART