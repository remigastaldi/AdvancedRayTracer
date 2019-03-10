#include "Object3D.hpp"
#include "Material.hpp"
#include "Mesh.hpp"

namespace ART {
namespace Logic {

Object3D::Object3D(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  new Modules::Material<Qt3DExtras::QMetalRoughMaterial>(*this, "Material");
  new Modules::Mesh<Qt3DRender::QMesh>(*this, "Mesh");
}

} // namespace Logic
} // namespace ART