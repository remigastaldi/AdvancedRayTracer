#pragma once

#include "globals.h"

#include <QQuickPaintedItem>

#include <memory>

namespace ART {
namespace Models {} // nameSpace Models

namespace Logic {

class Shape2D {
public:
  // Shape2D() = default;

  virtual void draw(QPainter *painter) noexcept  {};
};

} // namespace Logic
} // namespace ART