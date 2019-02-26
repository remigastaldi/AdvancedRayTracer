#include "Shape3D.hpp"

namespace ART {
namespace Logic {

Shape3D::Shape3D(Qt3DCore::QEntity *parent)
    : Qt3DCore::QEntity{parent}, _mesh{nullptr}, _material{nullptr},
     _transform{std::make_shared<Qt3DCore::QTransform>()} {
  addComponent(_transform.get());
}

Shape3D::Shape3D(Qt3DCore::QEntity *parent, std::shared_ptr<Qt3DRender::QGeometryRenderer> mesh,
  std::shared_ptr<Qt3DRender::QMaterial> material)
    : Qt3DCore::QEntity{parent}, _mesh{std::move(mesh)}, _material{std::move(material)},
    _transform{std::make_shared<Qt3DCore::QTransform>()} {
  
  _mesh->setParent(this);
  _material->setParent(this);
  addComponent(_mesh.get());
  addComponent(_material.get());
  addComponent(_transform.get());
}

void Shape3D::setMesh(std::shared_ptr<Qt3DRender::QGeometryRenderer> &mesh) noexcept {
  _mesh = mesh;
  _mesh->setParent(this);
}

std::shared_ptr<Qt3DRender::QGeometryRenderer> &Shape3D::mesh() noexcept {
  return _mesh;
}

std::shared_ptr<Qt3DRender::QMaterial> &Shape3D::material() noexcept {
  return _material;
}

std::shared_ptr<Qt3DCore::QTransform> &Shape3D::transform() noexcept {
  return _transform;
}

} // namespace Logic
} // namespace ART