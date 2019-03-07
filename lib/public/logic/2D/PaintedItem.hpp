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

  virtual void paint(QPainter *painter) override;
  virtual void mousePressEvent(QMouseEvent *event) override;
  virtual void mouseMoveEvent(QMouseEvent *event) override;
  virtual void mouseReleaseEvent(QMouseEvent *event) override;

private :
  Scene2D *_scene2D;
};

}
}