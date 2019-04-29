#include "Sphere.hpp"
#include "PhongAlphaMaterial.hpp"
#include "SphereMesh.hpp"
#include "WireframeMaterial.hpp"

namespace ART {
namespace Logic {

Sphere::Sphere(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  new Modules::SphereMesh(*this, "SphereMesh");
}

} // namespace Logic
} // namespace ART