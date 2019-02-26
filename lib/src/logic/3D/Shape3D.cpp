#include "Shape3D.hpp"

namespace ART {
namespace Logic {

Shape3D::Shape3D(Qt3DCore::QEntity *parent)
    : Qt3DCore::QEntity{parent}, _mesh{nullptr}, _material{nullptr},
     _transform{std::make_shared<Qt3DCore::QTransform>()} {
  addComponent(_transform.get());
}

Shape3D::Shape3D(Qt3DCore::QEntity *parent, Qt3DRender::QGeometryRenderer *mesh,
  Qt3DRender::QMaterial *material)
    : Qt3DCore::QEntity{parent}, _mesh{mesh}, _material{material},
    _transform{std::make_shared<Qt3DCore::QTransform>()} {
  
  _mesh->setParent(this);
  _material->setParent(this);
  addComponent(_mesh);
  addComponent(_material);
  addComponent(_transform.get());
}

void Shape3D::setMesh(Qt3DRender::QGeometryRenderer *mesh) noexcept {
  _mesh = mesh;
  _mesh->setParent(this);
}

Qt3DRender::QGeometryRenderer *Shape3D::mesh() noexcept {
  return _mesh;
}

Qt3DRender::QMaterial *Shape3D::material() noexcept {
  return _material;
}

std::shared_ptr<Qt3DCore::QTransform> &Shape3D::transform() noexcept {
  return _transform;
}

} // namespace Logic
} // namespace ART