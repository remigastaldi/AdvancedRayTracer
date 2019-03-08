#pragma once

#include "Shape2D.hpp"

namespace ART {
namespace Logic {

class Circle : public Shape2D {
public:
	Circle(std::string id);

  virtual void draw(QPainter *painter) noexcept override;
  virtual bool contains(int x, int y) const noexcept override;

private:
  QPainterPath _path;
};

} // namespace Logic
} // namespace ART