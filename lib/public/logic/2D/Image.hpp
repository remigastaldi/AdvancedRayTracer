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

private:
  QUrl _url;
  QImage _img;
};

} // namespace Logic
} // namespace ART