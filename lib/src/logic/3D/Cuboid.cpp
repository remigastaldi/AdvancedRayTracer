#include "Cuboid.hpp"
#include "MaterialPicker.hpp"
#include "CuboidMesh.hpp"
#include "PhongMaterial.hpp"

namespace ART {
namespace Logic {

Cuboid::Cuboid(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  new Modules::MaterialPicker(*this, "MaterialPicker");
  new Modules::CuboidMesh(*this, "CuboidMesh");
}

} // namespace Logic
} // namespace ART