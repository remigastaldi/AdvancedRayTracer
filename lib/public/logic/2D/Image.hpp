#pragma once

#include "Shape2D.hpp"
#include <QPainter>

namespace ART {
namespace Logic {

class Image : public Shape2D {
public:
  Image(std::string id);
  Image(QUrl imgUrl, std::string id);

  //Image(std::string id, const QUrl& imgUrl);

  virtual void draw(QPainter *painter) noexcept override;
  virtual bool contains(int x, int y) const noexcept override;

private:
  QUrl _url;
  QImage _img;
  QRectF _rect;
};

} // namespace Logic
} // namespace ART