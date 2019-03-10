#include "PaintedItem.hpp"
#include "Scene2D.hpp"

#include <iostream>

namespace ART {
namespace Logic {

PaintedItem::PaintedItem() {
  QQuickItem::setAntialiasing(true);
}

void PaintedItem::paint(QPainter *painter) {
  // _scene->paint(painter);
  Q_EMIT paintUpdate(painter);
}

void PaintedItem::mousePressEvent(QMouseEvent *event) {
  setFocus(true);
  Q_EMIT mousePressUpdate(event);
  // _scene->mousePressEvent(event);
}

void PaintedItem::mouseMoveEvent(QMouseEvent *event) {
  Q_EMIT mouseMoveUpdate(event);
  // _scene->mouseMoveEvent(event);
}

void PaintedItem::mouseReleaseEvent(QMouseEvent *event) {
  Q_EMIT mouseReleaseUpdate(event);
  // _scene->mouseReleaseEvent(event);
}

} // namespace Logic
} // namespace ART