#pragma once

#include "Shape2D.hpp"

namespace ART {
namespace Logic {

class Triangle : public Shape2D {
public:
  Triangle(std::string id);

  virtual void draw(QPainter *painter) noexcept override;
};

} // namespace Logic
} // namespace ART