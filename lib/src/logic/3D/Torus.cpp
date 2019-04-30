#include "Torus.hpp"
#include "MetalRoughMaterial.hpp"
#include "TorusMesh.hpp"

namespace ART {
namespace Logic {

Torus::Torus(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  auto *mesh = new Modules::TorusMesh(*this, "TorusMesh");

  mesh->setRadius(6);
  mesh->setSlices(50);
  mesh->setRings(100);
}

} // namespace Logic
} // namespace ART