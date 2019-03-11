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

double Pen::width() {
  return _pen.widthF();
}

QPen Pen::get() {
  return _pen;
}

void Pen::setColor(const QString &color) {
  _pen.setColor(color);
  Q_EMIT dataUpdate();
}

void Pen::setWidth(double width) {
  _pen.setWidthF(width);
}
} // namespace Modules
} // namespace Logic
} // namespace ART