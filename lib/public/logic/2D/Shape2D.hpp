#pragma once

#include "globals.h"

#include <QQuickPaintedItem>

#include <memory>

namespace ART {
namespace Models {} // nameSpace Models

namespace Logic {

class Shape2D {
public:
  int x1 = 0,
	  x2 = 0,
	  y1 = 0,
	  y2 = 0;
  QRect imgRect;

  virtual void draw(QPainter *painter) noexcept {};
};

} // namespace Logic
} // namespace ART