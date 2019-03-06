#pragma once

#include "Shape2D.hpp"

namespace ART {
namespace Logic {

class Rectangle : public Shape2D {
public:
  Rectangle(std::string id);

  virtual void draw(QPainter *painter) noexcept override;
};

} // namespace Logic
} // namespace ART