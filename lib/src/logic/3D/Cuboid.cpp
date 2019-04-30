#include "Cuboid.hpp"
#include "Material.hpp"
#include "CuboidMesh.hpp"
#include "PhongMaterial.hpp"

namespace ART {
namespace Logic {

Cuboid::Cuboid(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  auto *mesh = new Modules::CuboidMesh(*this, "CuboidMesh");
  mesh->setXExtent(4);
  mesh->setYExtent(4);
  mesh->setZExtent(4);
}

} // namespace Logic
} // namespace ART