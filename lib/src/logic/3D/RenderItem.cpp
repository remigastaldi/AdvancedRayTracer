#include "RenderItem.hpp"
#include "Scene2D.hpp"

#include <iostream>
#include <QPixmap>

namespace ART {
namespace Logic {

RenderItem::RenderItem() { QQuickItem::setAntialiasing(true); }

void RenderItem::paint(QPainter *painter) {
  // if (_render.empty()) {
  //   return;
  // }
  
  // painter->drawPixmap(0.0, 0.0, 1024, 768, QPixmap{reinterpret_cast<const char*>(_render.pixmap().data())});

  std::cout << "PAINT" << std::endl;
    // painter->setBrush(QColor("red"));
    // painter->drawRect(0, 0, 500, 500);
  // _scene->paint(painter);

  // Q_EMIT paintUpdate(painter);
}

void RenderItem::startRendering(std::unordered_map<std::string, std::unique_ptr<Entity>> &entities, const QVector3D &cameraPos) {
  _render.startRendering(entities, cameraPos);
  QQuickItem::update();
}

} // namespace Logic
} // namespace ART