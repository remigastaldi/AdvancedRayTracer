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
  // Q_PROPERTY(float colors READ colors NOTIFY dataUpdate)
  // Q_PROPERTY(float y READ y NOTIFY dataUpdate)
  // Q_PROPERTY(float z READ z NOTIFY dataUpdate)


public:
  Pen(Shape2D &parent, std::string id) : Entity{std::move(id)} {
    parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  }

public Q_SLOTS:
  // void setColor();

private:
  QPen _pen;
};

} // namespace Modules
} // namespace Logic
} // namespace ART
