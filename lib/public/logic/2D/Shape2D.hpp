#pragma once

#include "globals.h"
#include "Entity.hpp"

#include <QQuickPaintedItem>
#include <qpainterpath.h>
#include <QLine>

#include <memory>

namespace ART {
namespace Models {} // nameSpace Models

namespace Logic {
class Scene2D;

class Shape2D : public Entity {
public:
  int x1 = 0,
	  x2 = 0,
	  y1 = 0,
	  y2 = 0;
  QRect imgRect;
  QPainterPath shapeRect;
  QLine line;

  Shape2D(std::string id);
  virtual ~Shape2D() = default;

  virtual void draw(QPainter *painter) noexcept {};
};

} // namespace Logic
} // namespace ART