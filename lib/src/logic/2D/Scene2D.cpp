#include "Scene2D.hpp"
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
  std::unique_ptr<Rectangle> rect = std::make_unique<Rectangle>();
  _entities.emplace("Rectangle [0]", std::move(rect));
  QQuickPaintedItem::update();
}

void Scene2D::importImg(const QUrl &url) noexcept {
	std::unique_ptr<Logic::Image> img = std::make_unique<Logic::Image>(url);
	std::string objId = "Image [" + id;
	objId += "]";
	_entities.emplace(objId, std::move(img));
	id++;
	QQuickPaintedItem::update();
}

void Scene2D::mousePressEvent(QMouseEvent *event)
{

}

} // namespace Logic
} // namespace ART