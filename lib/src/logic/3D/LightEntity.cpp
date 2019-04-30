#include "LightEntity.hpp"

#include "Shape3D.hpp"
#include "SphereMesh.hpp"
#include "PhongAlphaMaterial.hpp"
#include "LightPicker.hpp"

namespace ART {
namespace Logic {


LightEntity::LightEntity(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  new Modules::SphereMesh(*this, "Mesh");
  new Modules::PhongAlphaMaterial(*this, "Material");
  new Modules::LightPicker(*this, "LightPicker");
}

} // namespace Logic
} // namespace ART