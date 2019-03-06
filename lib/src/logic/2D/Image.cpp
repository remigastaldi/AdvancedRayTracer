#include "Image.hpp"

namespace ART {
namespace Logic {

Image::Image() {}
Image::Image(const QUrl& imgUrl) {
	QString path;

	// If the path starts with a "/", we remove it so it will load properly
	if (imgUrl.path().at(0) == "/") {
		path = imgUrl.path().mid(1);
	}

	img = QImage(path);
	x1 = 0;
    y1 = 0;
    x2 = img.width();
    y2 = img.height();
}

void Image::draw(QPainter *painter) noexcept {
  imgRect = QRect(x1, y1, img.width(), img.height());

  painter->drawImage(imgRect, img);
}

} // namespace Logic
} // namespace ART