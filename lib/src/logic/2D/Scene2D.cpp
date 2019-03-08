#include "Scene2D.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "Polygon.hpp"
#include "Image.hpp"
#include "Line.hpp"
#include "PaintedItem.hpp"
#include "Rectangle.hpp"
#include "Shape2D.hpp"
#include "Triangle.hpp"
#include "ZIndex.hpp"
#include "Transform2D.hpp"

#include <QPainter>

namespace ART {
namespace Logic {

Scene2D::Scene2D(PaintedItem *painter) : _painter{painter}, selectedShape{nullptr} {
  _painter->setScene2D(this);
  _painter->setFillColor("black");
  _painter->setAcceptedMouseButtons(Qt::AllButtons);
  _painter->setAcceptHoverEvents(true);
}

void Scene2D::paint(QPainter *painter) {
  for (auto &elems : _zIndex) {
    for (auto &entity : elems.second) {
      entity.second.get()->draw(painter);
    }
  }
}

void Scene2D::createLine() noexcept {
  userIsDrawing = true;
  std::string objId = "Line [" + std::to_string(_id) + "]";
  std::unique_ptr<Line> line = std::make_unique<Line>(objId);
  _entities.emplace(objId, std::move(line));
  selectedShape = _entities.at(objId).get();
  new Modules::ZIndex(*this, *selectedShape, "zIndex");
  _id++;

  // Q_EMIT sceneUpdate();
}

void Scene2D::createRectangle() noexcept {
  userIsDrawing = true;
  std::string objId = "Rectangle [" + std::to_string(_id) + "]";

  std::unique_ptr<Rectangle> rect = std::make_unique<Rectangle>(objId);
  _entities.emplace(objId, std::move(rect));
  selectedShape = _entities.at(objId).get();
  new Modules::ZIndex(*this, *selectedShape, "zIndex");
  _id++;
  // _painter->QQuickItem::update();
  // Q_EMIT sceneUpdate();
  // Q_EMIT selectedShapeUpdate();
}

void Scene2D::createCircle() noexcept {
  userIsDrawing = true;
  std::string objId = "Circle [" + std::to_string(_id) + "]";
  std::unique_ptr<Circle> circle = std::make_unique<Circle>(objId);
  _entities.emplace(objId, std::move(circle));
  selectedShape = _entities.at(objId).get();
  new Modules::ZIndex(*this, *selectedShape, "zIndex");
  _id++;

  // Q_EMIT sceneUpdate();
}

void Scene2D::createTriangle() noexcept {
  userIsDrawing = true;
  std::string objId = "Triangle [" + std::to_string(_id) + "]";
  std::unique_ptr<Triangle> triangle = std::make_unique<Triangle>(objId);
  _entities.emplace(objId, std::move(triangle));
  selectedShape = _entities.at(objId).get();
  new Modules::ZIndex(*this, *selectedShape, "zIndex");
  // _painter->update();
  _id++;

  // Q_EMIT sceneUpdate();
}

void Scene2D::createPolygon() noexcept {
	userIsDrawing = true;
	std::string objId = "Polygon [" + std::to_string(_id) + "]";
	std::unique_ptr<Polygon> polygon = std::make_unique<Polygon>(objId);
	_entities.emplace(objId, std::move(polygon));
	selectedShape = _entities.at(objId).get();
	new Modules::ZIndex(*this, *selectedShape, "zIndex");
	// _painter->update();
	_id++;

	// Q_EMIT sceneUpdate();
}

void Scene2D::importImg(const QUrl &url) noexcept {
  std::string objId = "Image [" + std::to_string(_id) + "]";
  std::unique_ptr<Logic::Image> img = std::make_unique<Logic::Image>(url, objId);
  _entities.emplace(objId, std::move(img));
	selectedShape = _entities.at(objId).get();
  new Modules::ZIndex(*this, *_entities.at(objId), "zIndex");
  _id++;
  // _painter->update();

  // Q_EMIT sceneUpdate();
}

void Scene2D::saveScene(const QUrl &url) noexcept {
  QString path = url.path() + ".png";

  if (QSysInfo::kernelType().compare("winnt") == 0) {
    path = path.mid(1);
  }

  auto imgResult = _painter->grabToImage();
  connect(imgResult.data(), &QQuickItemGrabResult::ready, [=]() {
    imgResult->saveToFile(path);
    // imgResult->image() for a QImage instance of the output
  });
}

void Scene2D::mousePressEvent(QMouseEvent *event) {
  // shapePressed = false;
  if (userIsDrawing) {
			lastMouseX = event->x();
			lastMouseY = event->y();
			auto &trans = selectedShape->getChildren<Modules::Transform2D>("Transform");
			trans.move(event->x(), event->y());
  } else {
    selectedShape = nullptr;
    // Backward iteration into the map
    for (auto it = _entities.cbegin(); it != _entities.cend();) {
      // Did the user click on a shape?
      if (it->second->contains(event->x(), event->y())) {
        // Delete the shape
        if (event->buttons() == Qt::MiddleButton) {
          it = _entities.erase(it);
          _painter->update();
        } else {
          selectedShape = it->second.get();
          Q_EMIT selectedShapeUpdate();
					auto &trans = selectedShape->getChildren<Modules::Transform2D>("Transform");
					std::vector<QPointF> points{trans.getPoints()};
          decalx = event->x() - points[0].x();
          decaly = event->y() - points[0].y();
          lastMouseX = event->x();
          lastMouseY = event->y();
          ++it;
        }
      } else {
        ++it;
      }
    }
  }
}

void Scene2D::mouseMoveEvent(QMouseEvent *event) {
	auto &trans = selectedShape->getChildren<Modules::Transform2D>("Transform");
  if (userIsDrawing) {
    _painter->setCursor(QCursor(Qt::CrossCursor));
		trans.scale(event->x() - lastMouseX, event->y() - lastMouseY);
  } else if (selectedShape != nullptr) {
    // Move item
    if (event->buttons() == Qt::LeftButton) {
      _painter->setCursor(QCursor(Qt::ClosedHandCursor));
			trans.move(event->x() - decalx, event->y() - decaly);
      // Resize item
    } else if (event->buttons() == Qt::RightButton) {
      _painter->setCursor(QCursor(Qt::SizeAllCursor));
			trans.scale(event->x() - lastMouseX, event->y() - lastMouseY);
    }
  }
	lastMouseX = event->x();
	lastMouseY = event->y();

  _painter->update();
}

void Scene2D::mouseReleaseEvent(QMouseEvent *event) {
  shapePressed = false;
  _painter->setCursor(QCursor(Qt::ArrowCursor));

  if (userIsDrawing) {
    userIsDrawing = false;
    Q_EMIT sceneUpdate();
    Q_EMIT selectedShapeUpdate();
  }
}

const std::unordered_map<std::string, std::unique_ptr<Entity>> &Scene2D::entities() const noexcept {
  // TODO : Change this crap cast
  return reinterpret_cast<const std::unordered_map<std::string, std::unique_ptr<Entity>> &>(_entities);
}

void Scene2D::zIndexUpdate(size_t zIndex, const std::string &id) {
  _zIndex[zIndex].emplace(id, std::ref<std::unique_ptr<Shape2D>>(_entities.at(id)));
  _painter->QQuickItem::update();
  Q_EMIT sceneUpdate();
}

void Scene2D::zIndexDelete(size_t zIndex, const std::string &id) {
  _zIndex.at(zIndex).erase(id);
  Q_EMIT sceneUpdate();
}

} // namespace Logic
} // namespace ART