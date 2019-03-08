#include "Image.hpp"
#include "Transform2D.hpp"

#include <QSysInfo>

namespace ART {
namespace Logic {

Image::Image(std::string id) : Shape2D{std::move(id)}{}

Image::Image(QUrl imgUrl, std::string id) : Shape2D{std::move(id)}, _url{std::move(imgUrl)}, _rect{0,0,0,0} {
	// The path has to be different for the Windows os
	if (QSysInfo::kernelType().compare("winnt") == 0) {
		// If the path starts with a "/", we remove it so it will load properly
		if (_url.path().at(0) == "/") {
			QString fixedUrl(_url.path().mid(1));
			_img = QImage(fixedUrl);
		}
	} else {
		_img = QImage(_url.path());
	}
	auto &trans = getChildren<Modules::Transform2D>("Transform2D");
	trans.setWidth(_img.width());
	trans.setHeight(_img.height());
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
	auto &trans = getChildren<Modules::Transform2D>("Transform2D");
	_rect.setCoords(trans.x(), trans.y(), trans.width() + trans.x(), trans.height() + trans.y());
	painter->drawImage(_rect, _img);
}

bool Image::contains(int x, int y) const noexcept {
	return _rect.contains(QPoint(x, y));
}

} // namespace Logic
} // namespace ART