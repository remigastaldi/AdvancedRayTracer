#pragma once

#include "globals.h"
#include "Shape2D.hpp"

#include  <QQuickPaintedItem>
#include <unordered_map>
#include <QCursor>
#include <QQuickItemGrabResult>

namespace ART {

namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT Scene2D : public QQuickPaintedItem {
  Q_OBJECT
  Q_DISABLE_COPY(Scene2D)

public:
	const int SizeMinX = 50;
	const int SizeMinY = 50;

	int id = 0;
	int decalx = 0;
	int decaly = 0;
	int lastMouseX = 0;
	int lastMouseY = 0;
	bool shapePressed = false;
	bool userIsDrawing = false;
	bool drawingRectangle = false;
	bool drawingLine = false;
	bool drawingCircle = false;
	bool drawingTriangle = false;
    Shape2D *selectedShape;

    Scene2D();
    virtual void paint(QPainter *painter) override;

	void createLine() noexcept;
    void createRectangle() noexcept;
	void createCircle() noexcept;
	void createTriangle() noexcept;
	bool isCloseEnough(const QLineF& line, const QPointF& point);
    void importImg(const QUrl &url) noexcept;
	void saveScene(const QUrl &url) noexcept;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public Q_SLOTS:

private:
    std::map<std::string, std::unique_ptr<Shape2D>> _entities;
};
} // namespace Logic
} // namespace ART