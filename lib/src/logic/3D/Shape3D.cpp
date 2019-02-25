#include "Shape3D.hpp"

namespace ART {
namespace Logic {

Shape3D::Shape3D(Qt3DCore::QEntity *parent)
    : Qt3DCore::QEntity{parent},
      _material{std::make_unique<Qt3DExtras::QDiffuseSpecularMaterial>(this)},
      _mesh{std::make_unique<Qt3DExtras::QSphereMesh>(this)},
      _transform{std::make_unique<Qt3DCore::QTransform>()} {  
  addComponent(_mesh.get());
  addComponent(_material.get());
  addComponent(_transform.get());
}

std::shared_ptr<Qt3DRender::QMaterial> Shape3D::material() const noexcept {
  return _material;
}

std::shared_ptr<Qt3DExtras::QSphereMesh> Shape3D::mesh() const noexcept {
  return _mesh;
}

std::shared_ptr<Qt3DCore::QTransform> Shape3D::transform() const noexcept {
  return _transform;
}

} // namespace Logic
} // namespace ART