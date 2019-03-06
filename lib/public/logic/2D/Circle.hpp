#pragma once

#include "Shape2D.hpp"

namespace ART {
namespace Logic {

class Circle : public Shape2D {
public:
	Circle(std::string id);

  virtual void draw(QPainter *painter) noexcept override;
};

} // namespace Logic
} // namespace ART