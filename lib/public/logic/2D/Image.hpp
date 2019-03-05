#pragma once

#include "Shape2D.hpp"

namespace ART {
namespace Logic {

class Image : public Shape2D {
public:
  Image();
  Image(const QUrl& imgUrl);

  QUrl url;

  virtual void draw(QPainter *painter) noexcept override;
};

} // namespace Logic
} // namespace ART