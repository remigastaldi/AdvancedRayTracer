#pragma once

#include "globals.h"

#include <QCursor>
#include <QQuickItemGrabResult>
#include <QQuickPaintedItem>

namespace ART {
namespace Logic {
class Scene2D;

class ADVANCED_RAY_TRACER_EXPORT PaintedItem : public QQuickPaintedItem {
  Q_OBJECT
  Q_DISABLE_COPY(PaintedItem)

public:
  PaintedItem();

  virtual void paint(QPainter *painter) override ;
  virtual void mousePressEvent(QMouseEvent *event) override;
  virtual void mouseMoveEvent(QMouseEvent *event) override ;
  virtual void mouseReleaseEvent(QMouseEvent *event) override ;


public: void test(Scene2D *scene) { _scene = scene; }
Scene2D *_scene;


Q_SIGNALS:
  void mousePressUpdate(QMouseEvent *event);
  void mouseMoveUpdate(QMouseEvent *event);
  void mouseReleaseUpdate(QMouseEvent *event);
  void paintUpdate(QPainter *painter);
  void keyPressedEvent(Qt::Key key);
};

} // namespace Logic
} // namespace ART