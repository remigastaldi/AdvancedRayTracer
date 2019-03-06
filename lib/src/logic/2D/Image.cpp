#include "Image.hpp"

namespace ART {
namespace Logic {

Image::Image(std::string id) : Shape2D{std::move(id)}{}

Image::Image(QUrl imgUrl, std::string id) : Shape2D{std::move(id)}, _url{std::move(imgUrl)} {
	// If the path starts with a "/", we remove it so it will load properly
	// if (_url.path().at(0) == "/") {
	// 	_url = _url.path().mid(1);
	// }
	_img = QImage(_url.path());

	x2 = _img.width();
	y2 = _img.height();
}

/*Image::Image(std::string id, const QUrl& imgUrl) : Shape2D{std::move(id)}, _url{imgUrl} {
  // If the path starts with a "/", we remove it so it will load properly
  if (_url.path().at(0) == "/") {
	  _url = _url.path().mid(1);
  }
  _img.load(imgUrl.path());
}
*/

void Image::draw(QPainter *painter) noexcept {
	imgRect = QRect(x1, y1, _img.width(), _img.height());

	painter->drawImage(imgRect, _img);
}

} // namespace Logic
} // namespace ART