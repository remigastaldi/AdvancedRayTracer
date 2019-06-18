#pragma once

#include "globals.h"
#include "Geometry.hpp"
#include "Entity.hpp"
#include "Render.hpp"

#include <QCursor>
#include <QQuickItemGrabResult>
#include <QQuickPaintedItem>

#include <QPainter>

#include <unordered_map>
#include <memory>

namespace ART {
namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT RenderItem : public QQuickPaintedItem {
  Q_OBJECT
  Q_DISABLE_COPY(RenderItem)

public:
  RenderItem();

  virtual void paint(QPainter *painter) override;
  void startRendering(std::unordered_map<std::string, std::unique_ptr<Entity>> &entities, const QVector3D &cameraPos);
Q_SIGNALS:
  void paintUpdate(QPainter *painter);

private:
  Render _render;
};

} // namespace Logic
} // namespace ART