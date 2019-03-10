#pragma once

#include "globals.h"

#include "Entity.hpp"
#include "Shape2D.hpp"

#include <QObject>
#include <QPen>

namespace ART {
namespace Logic {

namespace Modules {

class ADVANCED_RAY_TRACER_EXPORT Pen : public Entity {
  Q_OBJECT
  Q_PROPERTY(QString color READ color NOTIFY dataUpdate)

public:
  Pen(Shape2D &parent, std::string id) : Entity{std::move(id)}, _pen{Qt::white, 5} {
    parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
    //_pen.setWidth(5);
  }

  QString color() {
    return _pen.color().name();
  }

  QPen get() {
    return _pen;
  }

public Q_SLOTS:
  void setColor(QString color) {
    _pen.setColor(color);
    Q_EMIT dataUpdate();
  }


Q_SIGNALS:
  void dataUpdate();

private:
  QPen _pen;
};

} // namespace Modules
} // namespace Logic
} // namespace ART
