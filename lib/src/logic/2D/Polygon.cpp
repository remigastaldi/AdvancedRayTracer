#include "Polygon.hpp"
#include <cmath>
#include <QPainter>

namespace ART {
namespace Logic {

Polygon::Polygon(std::string id) : Shape2D{std::move(id)} {}

void Polygon::draw(QPainter *painter) noexcept {
	painter->setBrush(Qt::blue);
	auto &trans = getChildren<Modules::Transform2D>("Transform2D");
	QPolygon polygon;
	const double pi = 3.1415926535897;
	int size = 50;
	int nb = 5;
	float theta = (2 * pi / nb);
	float dtheta = (2 * pi / nb);

	for (int i = 1; i <= nb; i++) {
		theta += dtheta;
		double pointX = (trans.x() + size * cos(theta));
		double pointY = (trans.y() + size * sin(theta));
		polygon << QPoint(pointX, pointY);
	}
	_path.addPolygon(polygon);
	painter->drawPolygon(polygon);
}

bool Polygon::contains(int x, int y) const noexcept { return _path.contains(QPointF(x, y)); }

} // namespace Logic
} // namespace ART