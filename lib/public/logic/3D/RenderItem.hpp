#pragma once

#include "globals.h"

#include <QCursor>
#include <QQuickItemGrabResult>
#include <QQuickPaintedItem>

#include <QPainter>

namespace ART {
namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT RenderItem : public QQuickPaintedItem {
  Q_OBJECT
  Q_DISABLE_COPY(RenderItem)

public:
  RenderItem();

  virtual void paint(QPainter *painter) override;
Q_SIGNALS:
  void paintUpdate(QPainter *painter);
};

} // namespace Logic
} // namespace ART