#pragma once

#include "Shape2D.hpp"

namespace ART {
namespace Logic {

class Rectangle : public Shape2D {
  Q_OBJECT
public:
  Rectangle(std::string id);

  virtual void draw(QPainter *painter) noexcept override;
  virtual bool contains(int x, int y) const noexcept override;
  // virtual void resize(int x, int y) noexcept override;

Q_SIGNALS:
  void dataUpdate();

private:
  QPainterPath _path;
};

} // namespace Logic
} // namespace ART