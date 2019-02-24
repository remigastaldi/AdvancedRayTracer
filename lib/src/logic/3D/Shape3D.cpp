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

} // namespace Logic
} // namespace ART