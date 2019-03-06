#include "Scene2D.hpp"
#include "Shape2D.hpp"
#include "Rectangle.hpp"
#include "Image.hpp"

#include <QPainter>

namespace ART {
namespace Logic {

Scene2D::Scene2D() {
  setFillColor("black");
  setAcceptedMouseButtons(Qt::AllButtons);
}

void Scene2D::paint(QPainter *painter) {
  for (auto & [ key, value ] : _entities) {
    value->draw(painter);
  }
}

void Scene2D::createRectangle() noexcept {
  std::unique_ptr<Rectangle> rect = std::make_unique<Rectangle>("Rectangle [0]");
  _entities.emplace("Rectangle [0]", std::move(rect));
  QQuickPaintedItem::update();
}

void Scene2D::importImg(const QUrl &url) noexcept {
	std::unique_ptr<Logic::Image> img = std::make_unique<Logic::Image>(url);
	std::string objId = "Image [" + std::to_string(id) + "]";
	_entities.emplace(objId, std::move(img));
	id++;
	QQuickPaintedItem::update();
}

void Scene2D::mousePressEvent(QMouseEvent *event) {
	// Backward iteration into the map
	for (auto it = _entities.rbegin(); it != _entities.rend(); ++it)
	{
		selectedShape = it->second.get();

		// Did the user click on a shape?
		if (selectedShape->imgRect.contains(event->x(), event->y()))
		{
			decalx = event->x();
			decaly = event->y();
			shapePressed = true;
			break;
		}
	}
}

void Scene2D::mouseMoveEvent(QMouseEvent *event) {
	if (shapePressed) {
		selectedShape->x1 = event->x() - decalx;
		selectedShape->y1 = event->y() - decaly;
		QQuickPaintedItem::update();
	}
}

void Scene2D::mouseReleaseEvent(QMouseEvent *event) {
	shapePressed = false;
}

} // namespace Logic
} // namespace ART