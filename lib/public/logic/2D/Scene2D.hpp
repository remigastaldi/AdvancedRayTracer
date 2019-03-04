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

  Scene2D();
  virtual void paint(QPainter *painter) override;

  void createRectangle() noexcept;
  void importImg(const QUrl &url) noexcept;

  void mousePressEvent(QMouseEvent *event);

public Q_SLOTS:

private:
  std::unordered_map<std::string, std::unique_ptr<Shape2D>> _entities;
};
} // namespace Logic
} // namespace ART