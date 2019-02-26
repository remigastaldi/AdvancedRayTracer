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
  explicit Shape3D(Qt3DCore::QEntity *parent);
  Shape3D(Qt3DCore::QEntity *parent, Qt3DRender::QGeometryRenderer *mesh,
          Qt3DRender::QMaterial *material);

  void setMesh(Qt3DRender::QGeometryRenderer *mesh) noexcept;

  template<typename T>
  T *mesh() noexcept {
    return dynamic_cast<T*>(_mesh);
  }

  virtual Qt3DRender::QGeometryRenderer *mesh() noexcept;
  virtual Qt3DRender::QMaterial *material() noexcept;
  virtual std::shared_ptr<Qt3DCore::QTransform> &transform() noexcept;

private:
  Qt3DRender::QGeometryRenderer *_mesh;
  Qt3DRender::QMaterial *_material;
  std::shared_ptr<Qt3DCore::QTransform> _transform;
};
} // namespace Logic
} // namespace ART