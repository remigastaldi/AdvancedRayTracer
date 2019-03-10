#include "Triangle.hpp"
#include "Brush.hpp"
#include "Pen.hpp"
#include "Transform2D.hpp"

#include <QPainter>

#include <cmath>

namespace ART {
namespace Logic {

Triangle::Triangle(std::string id) : Shape2D{std::move(id)} {
  auto *brush = new Modules::Brush(*this, "Brush");
  connect(brush, &Modules::Brush::dataUpdate, this, &Triangle::dataUpdate);
  auto *pen = new Modules::Pen(*this, "Pen");
  connect(pen, &Modules::Pen::dataUpdate, this, &Triangle::dataUpdate);
  new Modules::Pen(*this, "Pen");
  auto &trans = getChildren<Modules::Transform2D>("Transform2D");
  trans.setAngle(270);
}

void Triangle::draw(QPainter *painter) noexcept {
  /*_path = QPainterPath();
  auto &brush = getChildren<Modules::Brush>("Brush");
  painter->setBrush(brush.get());
  auto &pen = getChildren<Modules::Pen>("Pen");
  painter->setPen(pen.get());
  auto &trans = getChildren<Modules::Transform2D>("Transform2D");  
  //QRect rect = QRect(trans.x(), trans.y(), trans.width(), trans.height());

  QRect r(trans.x(), trans.y(), trans.width(), trans.height());
  QPoint center = r.center();
  QTransform t = QTransform().translate(center.x(), center.y()).rotate(trans.angle()).translate(-center.x(), -center.y());
  QRect rect = t.mapRect(r);
  //_path.addPolygon(rotatedRect);
  //painter->drawPolygon(rotatedRect);

  _path.moveTo(rect.left() + (rect.width() / 2), rect.top());
  _path.lineTo(rect.bottomLeft());
  _path.lineTo(rect.bottomRight());
  _path.lineTo(rect.left() + (rect.width() / 2), rect.top());

  painter->drawPath(_path);*/

	_path = QPainterPath();
	auto &brush = getChildren<Modules::Brush>("Brush");
	painter->setBrush(brush.get());
	auto &pen = getChildren<Modules::Pen>("Pen");
	painter->setPen(pen.get());
	auto &trans = getChildren<Modules::Transform2D>("Transform2D");

	QPolygon polygon;
	const double pi = 3.1415926535897;
	int size = trans.width();
	int nb = 3;
	float theta = (2 * pi / nb);
	float dtheta = (2 * pi / nb);
	QPoint center(0, 0);

	for (int i = 1; i <= nb; i++) {
		theta += dtheta;
		double pointX = (trans.x() + size * cos(theta));
		double pointY = (trans.y() + size * sin(theta));
		polygon << QPoint(pointX, pointY);
		center.setX(center.x() + pointX);
		center.setY(center.y() + pointY);
	}

	center.setX(center.x() / nb);
	center.setY(center.y() / nb);

	QTransform t = QTransform().translate(center.x(), center.y()).rotate(trans.angle()).translate(-center.x(), -center.y());
	QPolygon rotatedPolygon = t.map(polygon);

	_path.addPolygon(rotatedPolygon);
	painter->drawPolygon(rotatedPolygon);
}

bool Triangle::contains(int x, int y) const noexcept {
  return _path.contains(QPointF(x, y));
}

} // namespace Logic
} // namespace ART