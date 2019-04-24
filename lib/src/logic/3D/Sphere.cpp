#include "Sphere.hpp"
#include "Material.hpp"
#include "SphereMesh.hpp"

namespace ART {
namespace Logic {

Sphere::Sphere(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  new Modules::Material<>(*this, "Material");
  new Modules::SphereMesh(*this, "SphereMesh");
}

} // namespace Logic
} // namespace ART