#include "PaintedItem.hpp"
#include "Scene2D.hpp"

#include <iostream>

namespace ART {
namespace Logic {

void PaintedItem::setScene2D(Scene2D *scene2D) {
  _scene2D = scene2D;
}

void PaintedItem::paint(QPainter *painter) {
  if (_scene2D != nullptr) {
    _scene2D->paint(painter);
  }
}

void PaintedItem::mousePressEvent(QMouseEvent *event) { 
  if (_scene2D != nullptr) {
    _scene2D->mousePressEvent(event);
  }
  setFocus(true);
}

void PaintedItem::mouseMoveEvent(QMouseEvent *event) { 
  if (_scene2D != nullptr) {
    _scene2D->mouseMoveEvent(event);
  }
}

void PaintedItem::mouseReleaseEvent(QMouseEvent *event) { 
  if (_scene2D != nullptr) {
    _scene2D->mouseReleaseEvent(event);
  }
}

void PaintedItem::keyPressedEvent(Qt::Key key) {
  if (_scene2D != nullptr) {
    _scene2D->keyPressedEvent(key);
  }
}

} // namespace Logic
} // namespace ART