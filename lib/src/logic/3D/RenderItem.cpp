#include "RenderItem.hpp"
#include "Scene2D.hpp"

#include <iostream>

namespace ART {
namespace Logic {

RenderItem::RenderItem() { QQuickItem::setAntialiasing(true); }

void RenderItem::paint(QPainter *painter) {
  qInfo() << "dddd";

  painter->setBrush(QColor("red"));
  painter->drawRect(0, 0, 500, 500);
  // _scene->paint(painter);

  // Q_EMIT paintUpdate(painter);
}

} // namespace Logic
} // namespace ART