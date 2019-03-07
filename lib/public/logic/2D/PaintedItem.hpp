#pragma once

#include "globals.h"

#include <QQuickPaintedItem>
#include <QCursor>
#include <QQuickItemGrabResult>

namespace ART {
namespace Logic {
class Scene2D;

class ADVANCED_RAY_TRACER_EXPORT PaintedItem : public QQuickPaintedItem {
  Q_OBJECT
  Q_DISABLE_COPY(PaintedItem)

public:
  PaintedItem() {};

  void setScene2D(Scene2D *scene2D);

// public Q_SLOTS:
  virtual void paint(QPainter *painter) override;
// Q_SIGNALS:
  // void paintEvent(QPainter *painter);

private :
  Scene2D *_scene2D;
};

}
}