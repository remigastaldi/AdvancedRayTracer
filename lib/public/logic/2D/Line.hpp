#pragma once

#include "Shape2D.hpp"

namespace ART {
namespace Logic {

class Line : public Shape2D {
public:
  Line(std::string id);

  virtual void draw(QPainter *painter) noexcept override;
};

} // namespace Logic
} // namespace ART