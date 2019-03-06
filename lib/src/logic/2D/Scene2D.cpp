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
  setAcceptHoverEvents(true);
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
	std::string objId = "Image [" + std::to_string(id) + "]";
	std::unique_ptr<Logic::Image> img = std::make_unique<Logic::Image>(url, objId);
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
		// Move item
		if (event->buttons() == Qt::LeftButton) {
			this->setCursor(QCursor(Qt::ClosedHandCursor));
			selectedShape->x1 = event->x() - decalx;
			selectedShape->y1 = event->y() - decaly;
		// Resize item
		} else if (event->buttons() == Qt::RightButton) {
			this->setCursor(QCursor(Qt::SizeAllCursor));

			// x resize
			if (lastMouseX != event->x()) {
				// bigger
				if (lastMouseX < event->x()) {
					selectedShape->x2 += (event->x() - lastMouseX);
				// smaller
				} else if (selectedShape->x2 >= SizeMinX) {
					selectedShape->x2 -= (lastMouseX - event->x());
				}
			}
			
			// y resize
			if (lastMouseY != event->y()) {
				// bigger
				if (lastMouseX < event->x()) {
					selectedShape->y2 += (event->y() - lastMouseY);
				// smaller
				} else if (selectedShape->y2 >= SizeMinY) {
					selectedShape->y2 -= (lastMouseY - event->y());
				}
			}

			lastMouseX = event->x();
			lastMouseY = event->y();
		}

		QQuickPaintedItem::update();
	}
}

void Scene2D::mouseReleaseEvent(QMouseEvent *event) {
	shapePressed = false;
	this->setCursor(QCursor(Qt::ArrowCursor));
}

} // namespace Logic
} // namespace ART