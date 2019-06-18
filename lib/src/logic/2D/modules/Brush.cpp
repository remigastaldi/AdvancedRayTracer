#include "Brush.hpp"

namespace ART {
namespace Logic {
namespace Modules {

Brush::Brush(Shape2D &parent, std::string id) : Entity{std::move(id)}, _brush{Qt::white} {
  parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
}

QString Brush::color() {
  return _brush.color().name();
}

QBrush Brush::get() {
  return _brush;
}

void Brush::setColor(const QString &color) {
  _brush.setColor(color);
  Q_EMIT dataUpdate();
}


} // namespace Modules
} // namespace Logic
} // namespace ART