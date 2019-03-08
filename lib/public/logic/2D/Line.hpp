#pragma once

#include "Shape2D.hpp"

namespace ART {
namespace Logic {

class Line : public Shape2D {
public:
  Line(std::string id);

  virtual void draw(QPainter *painter) noexcept override;
  virtual bool contains(int x, int y) const noexcept override;
  // virtual std::vector<QPointF> getPoints() const noexcept override;

private:
  // QPainterPath _path;
  QLineF _line;
};

} // namespace Logic
} // namespace ART