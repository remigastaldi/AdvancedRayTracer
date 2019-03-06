#pragma once

#include "globals.h"
#include "Shape2D.hpp"

#include  <QQuickPaintedItem>
#include <unordered_map>

namespace ART {

namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT Scene2D : public QQuickPaintedItem {
  Q_OBJECT
  Q_DISABLE_COPY(Scene2D)

public:
  int id = 0;
  int decalx = 0;
  int decaly = 0;
  bool shapePressed = false;
  Shape2D *selectedShape;

  Scene2D();
  virtual void paint(QPainter *painter) override;

  void createRectangle() noexcept;
  void importImg(const QUrl &url) noexcept;

  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);

public Q_SLOTS:

private:
  std::map<std::string, std::unique_ptr<Shape2D>> _entities;
};
} // namespace Logic
} // namespace ART