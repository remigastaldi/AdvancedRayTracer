#include "Polygon.hpp"
#include <cmath>
#include <QPainter>

namespace ART {
namespace Logic {

Polygon::Polygon(std::string id) : Shape2D{std::move(id)} {}

void Polygon::draw(QPainter *painter) noexcept {
	painter->setBrush(Qt::blue);

	QPolygon polygon;
	double pi = 3.1415926535897;
	//int size = 50;
	int nb = 5;
	float theta = (2 * pi / nb);
	float dtheta = (2 * pi / nb);

	for (int i = 1; i <= nb; i++) {
		theta += dtheta;
		// double pointX = (x1 + size * cos(theta));
		// double pointY = (y1 + size * sin(theta));
		//qInfo() << pointX << " " << pointY;
		// polygon << QPoint(pointX, pointY);
	}

	painter->drawPolygon(polygon);
}

} // namespace Logic
} // namespace ART