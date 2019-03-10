#include "Pen.hpp"

namespace ART {
namespace Logic {
namespace Modules {

Pen::Pen(Shape2D &parent, std::string id) : Entity{std::move(id)}, _pen{Qt::white, 5} {
  parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
}

QString Pen::color() {
  return _pen.color().name();
}

QPen Pen::get() {
  return _pen;
}

void Pen::setColor(QString color) {
  _pen.setColor(color);
  Q_EMIT dataUpdate();
}

} // namespace Modules
} // namespace Logic
} // namespace ART