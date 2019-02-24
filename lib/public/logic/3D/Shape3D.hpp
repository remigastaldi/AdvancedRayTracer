#pragma once

#include "globals.h"

#include <QEntity>
#include <Qt3DExtras>
#include <Qt3DRender>

#include <memory>

namespace ART {
namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT Shape3D : public Qt3DCore::QEntity {
  Q_OBJECT
  Q_DISABLE_COPY(Shape3D)

public:
  Shape3D(Qt3DCore::QEntity *parent);

  std::shared_ptr<Qt3DRender::QMaterial> material() {
    return _material;
  }

  std::shared_ptr<Qt3DExtras::QSphereMesh> mesh() {
    return _mesh;
  }

  std::shared_ptr<Qt3DCore::QTransform> transform() {
    return _transform;
  }

private:
  std::shared_ptr<Qt3DRender::QMaterial> _material;
  std::shared_ptr<Qt3DExtras::QSphereMesh> _mesh;
  std::shared_ptr<Qt3DCore::QTransform> _transform;
};
} // namespace Logic
} // namespace ART