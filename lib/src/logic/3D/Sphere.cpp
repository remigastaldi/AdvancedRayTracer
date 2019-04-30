#include "Sphere.hpp"
#include "PhongAlphaMaterial.hpp"
#include "SphereMesh.hpp"
#include "WireframeMaterial.hpp"

namespace ART {
namespace Logic {

Sphere::Sphere(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  auto *mesh = new Modules::SphereMesh(*this, "SphereMesh");
  mesh->setRadius(4);
  mesh->setSlices(50);
  mesh->setRings(50);
}

} // namespace Logic
} // namespace ART