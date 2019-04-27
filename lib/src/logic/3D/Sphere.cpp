#include "Sphere.hpp"
#include "MetalRoughMaterial.hpp"
#include "SphereMesh.hpp"

namespace ART {
namespace Logic {

Sphere::Sphere(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  new Modules::MetalRoughMaterial(*this, "MetalRoughMaterial");
  new Modules::SphereMesh(*this, "SphereMesh");
}

} // namespace Logic
} // namespace ART