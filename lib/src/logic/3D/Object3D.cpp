#include "Object3D.hpp"
#include "Mesh.hpp"
#include "MaterialPicker.hpp"


namespace ART {
namespace Logic {

Object3D::Object3D(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  new Modules::MaterialPicker(*this, "MaterialPicker");
  new Modules::Mesh<Qt3DRender::QMesh>(*this, "Mesh");
}

} // namespace Logic
} // namespace ART