#pragma once

#include "globals.h"
#include "Entity.hpp"

#include <QQuickPaintedItem>
#include <qpainterpath.h>
#include <QLine>
#include <qimage.h>

#include <memory>

namespace ART {
namespace Models {} // nameSpace Models

namespace Logic {
class Scene2D;

class Shape2D : public Entity {
public:
  Shape2D(std::string id);
  virtual ~Shape2D() = default;

  virtual void draw(QPainter *painter) noexcept {};
  virtual bool contains(int x, int y) const noexcept { return false; };
  virtual QImage crop(int x1, int y1, int x2, int y2) noexcept { return QImage(); };
};

} // namespace Logic
} // namespace ART