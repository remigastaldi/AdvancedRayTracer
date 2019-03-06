#include "Image.hpp"

namespace ART {
namespace Logic {

Image::Image(std::string id, const QUrl& imgUrl) : Shape2D{std::move(id)}, _url{imgUrl} {
  // If the path starts with a "/", we remove it so it will load properly
  if (_url.path().at(0) == "/") {
	  _url = _url.path().mid(1);
  }
  _img.load(imgUrl.path());
}

void Image::draw(QPainter *painter) noexcept {
  // std::cout << "DRAW" << _img << std::endl;

  painter->drawImage(QRect(0, 0, _img.width(), _img.height()), _img);
}

} // namespace Logic
} // namespace ART