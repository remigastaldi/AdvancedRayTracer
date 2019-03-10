#pragma once

#include "Transform2D.hpp"
#include "Shape2D.hpp"

namespace ART {
namespace Logic {

class Polygon : public Shape2D {
  Q_OBJECT

public:
	Polygon(std::string id);

  virtual void draw(QPainter *painter) noexcept override;
  virtual bool contains(int x, int y) const noexcept override;

  QPainterPath _path;

Q_SIGNALS:
  void dataUpdate();
};

} // namespace Logic
} // namespace ART