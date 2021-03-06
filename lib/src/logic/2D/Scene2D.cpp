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

Scene2D::Scene2D(PaintedItem *painter) : _painter{painter}, _selectedShape{nullptr} {
// Windows crash with signals, find why and remove this
  _painter->setScene2D(this);

  _painter->setFillColor("black");
  _painter->setAcceptedMouseButtons(Qt::AllButtons);
  _painter->setAcceptHoverEvents(true);

  // connect(_painter, &PaintedItem::paintUpdate, this, &Scene2D::paint);
  // connect(_painter, &PaintedItem::mousePressUpdate, this, &Scene2D::mousePressEvent);
  // connect(_painter, &PaintedItem::mouseMoveUpdate, this, &Scene2D::mouseMoveEvent);
  // connect(_painter, &PaintedItem::mouseReleaseUpdate, this, &Scene2D::mouseReleaseEvent);
  connect(_painter, &PaintedItem::keyPressedEvent, this, &Scene2D::keyPressedEvent);
}

void Scene2D::paint(QPainter *painter) {
  painter->setRenderHint(QPainter::Antialiasing);
  for (auto &elems : _zIndex) {
    for (auto &entity : elems.second) {
      entity.second.get()->draw(painter);
    }
  }
}

void Scene2D::createLine() noexcept {
  _painter->setCursor(QCursor(Qt::PointingHandCursor));
  userIsDrawing = true;
  std::string objId = "Line [" + std::to_string(_id) + "]";
  std::unique_ptr<Line> line = std::make_unique<Line>(objId);
  connect(line.get(), &Line::dataUpdate, _painter, &PaintedItem::QQuickItem::update);
  _entities.emplace(objId, std::move(line));
  _selectedShape = _entities.at(objId).get();
  new Modules::ZIndex(*this, *_selectedShape, "ZIndex");
  _id++;
  // Q_EMIT sceneUpdate();
}

void Scene2D::createRectangle() noexcept {
  _painter->setCursor(QCursor(Qt::PointingHandCursor));
  userIsDrawing = true;
  std::string objId = "Rectangle [" + std::to_string(_id) + "]";

  std::unique_ptr<Rectangle> rect = std::make_unique<Rectangle>(objId);
  connect(rect.get(), &Rectangle::dataUpdate, _painter, &PaintedItem::QQuickItem::update);
  _entities.emplace(objId, std::move(rect));
  _selectedShape = _entities.at(objId).get();
  new Modules::ZIndex(*this, *_selectedShape, "ZIndex");
  _id++;
  // _painter->QQuickItem::update();
  // Q_EMIT sceneUpdate();
  // Q_EMIT selectedShapeUpdate();
}

void Scene2D::createCircle() noexcept {
  _painter->setCursor(QCursor(Qt::PointingHandCursor));
  userIsDrawing = true;
  std::string objId = "Circle [" + std::to_string(_id) + "]";
  std::unique_ptr<Circle> circle = std::make_unique<Circle>(objId);
  connect(circle.get(), &Circle::dataUpdate, _painter, &PaintedItem::QQuickItem::update);
  _entities.emplace(objId, std::move(circle));
  _selectedShape = _entities.at(objId).get();
  new Modules::ZIndex(*this, *_selectedShape, "ZIndex");
  _id++;

  // Q_EMIT sceneUpdate();
}

void Scene2D::createTriangle() noexcept {
  _painter->setCursor(QCursor(Qt::PointingHandCursor));
  userIsDrawing = true;
  std::string objId = "Triangle [" + std::to_string(_id) + "]";
  std::unique_ptr<Triangle> triangle = std::make_unique<Triangle>(objId);
  connect(triangle.get(), &Triangle::dataUpdate, _painter, &PaintedItem::QQuickItem::update);
  _entities.emplace(objId, std::move(triangle));
  _selectedShape = _entities.at(objId).get();
  new Modules::ZIndex(*this, *_selectedShape, "ZIndex");
  // _painter->update();
  _id++;

  // Q_EMIT sceneUpdate();
}

void Scene2D::createPolygon() noexcept {
	_painter->setCursor(QCursor(Qt::PointingHandCursor));
	userIsDrawing = true;
	std::string objId = "Polygon [" + std::to_string(_id) + "]";
	std::unique_ptr<Polygon> polygon = std::make_unique<Polygon>(objId);
  connect(polygon.get(), &Polygon::dataUpdate, _painter, &PaintedItem::QQuickItem::update);
	_entities.emplace(objId, std::move(polygon));
	_selectedShape = _entities.at(objId).get();
	new Modules::ZIndex(*this, *_selectedShape, "ZIndex");
	// _painter->update();
	_id++;

	// Q_EMIT sceneUpdate();
}

void Scene2D::cutImage() noexcept {
	_painter->setCursor(QCursor(Qt::CrossCursor));
	cutImg = true;
}

void Scene2D::importImg(const QUrl &url) noexcept {
  std::string objId = "Image [" + std::to_string(_id) + "]";
  std::unique_ptr<Logic::Image> img = std::make_unique<Logic::Image>(url, objId);
  _entities.emplace(objId, std::move(img));
  _selectedShape = _entities.at(objId).get();
  new Modules::ZIndex(*this, *_selectedShape, "ZIndex");
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

void Scene2D::setBackgroundColor(const QColor &color) noexcept {
  _painter->setFillColor(color);
}

void Scene2D::mousePressEvent(QMouseEvent *event) {
  if (userIsDrawing) {
	  if (event->buttons() == Qt::RightButton) {
		  userIsDrawing = false;
	  } else {
		lastMouseX = event->x();
		lastMouseY = event->y();
		auto &trans = _selectedShape->getChildren<Modules::Transform2D>("Transform2D");
		trans.move(event->x(), event->y());
	  }
  } else {
    for (auto it = _zIndex.rbegin(); it != _zIndex.rend(); ++it) {
      for (auto entity = it->second.rbegin(); entity != it->second.rend(); ++ entity) {
      // Did the user click on a shape?
        if (entity->second.get()->contains(event->x(), event->y())) {
          // Delete the shape
          if (event->buttons() == Qt::MiddleButton) {
			      _painter->setCursor(QCursor(Qt::ForbiddenCursor));
            _entities.erase(entity->first);
            _selectedShape = nullptr;
            _painter->update();
            return;
          }
          _selectedShape = entity->second.get().get();
          Q_EMIT selectedShapeUpdate();
          auto &trans = _selectedShape->getChildren<Modules::Transform2D>("Transform2D");
          std::vector<QPointF> points{trans.getPoints()};
          decalx = event->x() - static_cast<int>(points[0].x());
          decaly = event->y() - static_cast<int>(points[0].y());
          lastMouseX = event->x();
          lastMouseY = event->y();
          return;
        }
      }
    }
    _selectedShape = nullptr;
    Q_EMIT selectedShapeUpdate();
  }
}

void Scene2D::mouseMoveEvent(QMouseEvent *event) {
  if (_selectedShape != nullptr && !cutImg) {
    auto &trans = _selectedShape->getChildren<Modules::Transform2D>("Transform2D");
    if (userIsDrawing) {
      _painter->setCursor(QCursor(Qt::CrossCursor));
      trans.scale(event->x() - lastMouseX, event->y() - lastMouseY);
    } else if (_selectedShape != nullptr) {
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
    _painter->update();
  }

  // Only update the last mouse position if we're not cropping an image
  if (!cutImg) {
	  lastMouseX = event->x();
	  lastMouseY = event->y();
  }
}

void Scene2D::mouseReleaseEvent(QMouseEvent *event) {
  _painter->setCursor(QCursor(Qt::ArrowCursor));

  // Image crop
  if (_selectedShape != nullptr && cutImg) {
	  QImage crpImg = _selectedShape->crop(lastMouseX, lastMouseY, event->x() - lastMouseX, event->y() - lastMouseY);
	  if (!crpImg.isNull()) {
		  std::string objId = "Image [" + std::to_string(_id) + "]";
		  std::unique_ptr<Logic::Image> img = std::make_unique<Logic::Image>(crpImg, objId);
		  _entities.emplace(objId, std::move(img));
		  _selectedShape = _entities.at(objId).get();
		  new Modules::ZIndex(*this, *_selectedShape, "zIndex");
		  _id++;
      // For button color update
      Q_EMIT isDrawingChanged(false);
	  }
  }

  cutImg = false;

  if (userIsDrawing) {
    userIsDrawing = false;
    Q_EMIT isDrawingChanged(false);
    Q_EMIT sceneUpdate();
    Q_EMIT selectedShapeUpdate();
  }
}

void Scene2D::keyPressedEvent(Qt::Key event) {
  switch (event) {
    case Qt::Key_Delete:
        deleteSelectedEntity();
      break;
    default:
      break;
  }
}


const std::unordered_map<std::string, std::unique_ptr<Entity>> &Scene2D::entities() const noexcept {
  // TODO : Change this crap cast
  return reinterpret_cast<const std::unordered_map<std::string, std::unique_ptr<Entity>> &>(_entities);
}

Entity *Scene2D::selectedEntity() const noexcept {
  return _selectedShape;
}

void Scene2D::selectEntity(const std::string & id) noexcept {
  auto shape = _entities.find(id);

  if (shape != _entities.cend()) {
    _selectedShape = shape->second.get();
  }
  Q_EMIT selectedShapeUpdate();
}

void Scene2D::deleteSelectedEntity() noexcept {
  if (_selectedShape != nullptr) {
    _entities.erase(_selectedShape->id());
    _selectedShape = nullptr;
    _painter->QQuickItem::update();
    Q_EMIT sceneUpdate();
    Q_EMIT selectedShapeUpdate();
  }
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

void Scene2D::update() noexcept {
  _painter->QQuickItem::update();
}

} // namespace Logic
} // namespace ART