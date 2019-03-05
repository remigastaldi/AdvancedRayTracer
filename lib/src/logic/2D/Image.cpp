#include "Image.hpp"

#include <QPainter>

namespace ART {
namespace Logic {

Image::Image() {}
Image::Image(const QUrl& imgUrl) {
	url = imgUrl;
}

void Image::draw(QPainter *painter) noexcept {
	QString path;

  // If the path starts with a "/", we remove it so it will load properly
  if (url.path().at(0) == "/") {
	  path = url.path().mid(1);
  }

  QImage img(path);

  painter->drawImage(QRect(0, 0, img.width(), img.height()), QImage(path));
}

} // namespace Logic
} // namespace ART