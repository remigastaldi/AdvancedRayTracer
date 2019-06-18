#pragma once

#include "Shape2D.hpp"

namespace ART {
namespace Logic {

class Triangle : public Shape2D {
  Q_OBJECT
public:
  Triangle(std::string id);

  virtual void draw(QPainter *painter) noexcept override;
  virtual bool contains(int x, int y) const noexcept override;

Q_SIGNALS:
  void dataUpdate();

private:
  QPainterPath _path;
};

} // namespace Logic
} // namespace ART