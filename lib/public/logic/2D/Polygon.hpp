#pragma once

#include "Shape2D.hpp"

namespace ART {
namespace Logic {

class Polygon : public Shape2D {
public:
	Polygon(std::string id);

  virtual void draw(QPainter *painter) noexcept override;
};

} // namespace Logic
} // namespace ART