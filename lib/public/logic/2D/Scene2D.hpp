#pragma once

#include "globals.h"

#include  <QQuickPaintedItem>

namespace ART {
namespace Models {} // nameSpace Models

namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT Scene2D : public QQuickPaintedItem {
  Q_OBJECT
  Q_DISABLE_COPY(Scene2D)

public:
  Scene2D();
  virtual void paint(QPainter *painter) override;

  void createRectangle() noexcept;

public Q_SLOTS:

private:
};
} // namespace Logic
} // namespace ART