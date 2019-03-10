#pragma once

#include "globals.h"

#include "Entity.hpp"
#include "Shape2D.hpp"

#include <QObject>
#include <QVariantHash>
#include <QBrush>

namespace ART {
namespace Logic {

namespace Modules {

class ADVANCED_RAY_TRACER_EXPORT Brush : public Entity {
  Q_OBJECT
  Q_PROPERTY(QString color READ color NOTIFY dataUpdate)
  // Q_PROPERTY(float y READ y NOTIFY dataUpdate)
  // Q_PROPERTY(float z READ z NOTIFY dataUpdate)


public:
  Brush(Shape2D &parent, std::string id) : Entity{std::move(id)}, _brush{Qt::white} {
    parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  }

  QString color() {
    return _brush.color().name();
  }

  QBrush get() {
    return _brush;
  }

public Q_SLOTS:
  void setColor(QString color) {
    _brush.setColor(color);
    Q_EMIT dataUpdate();
  }

private:
  QBrush _brush;

Q_SIGNALS:
  void dataUpdate();
};

} // namespace Modules
} // namespace Logic
} // namespace ART
