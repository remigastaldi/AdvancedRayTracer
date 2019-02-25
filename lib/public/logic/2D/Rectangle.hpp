#pragma once

#include "Shape2D.hpp"

namespace ART {
namespace Logic {

class Rectangle : public Shape2D {
public:
  Rectangle();

  virtual void draw(QPainter *painter) noexcept override;
};

} // namespace Logic
} // namespace ART