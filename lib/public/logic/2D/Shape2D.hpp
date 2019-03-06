#pragma once

#include "globals.h"
#include "Entity.hpp"

#include <QQuickPaintedItem>

#include <memory>

namespace ART {
namespace Models {} // nameSpace Models

namespace Logic {

class Shape2D : public Entity {
public:
  Shape2D(std::string id);

  virtual void draw(QPainter *painter) noexcept {};
};

} // namespace Logic
} // namespace ART