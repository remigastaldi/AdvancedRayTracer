#include "Sphere.hpp"
#include "PhongAlphaMaterial.hpp"
#include "SphereMesh.hpp"

namespace ART {
namespace Logic {

Sphere::Sphere(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  new Modules::PhongAlphaMaterial(*this, "PhongAlphaMaterial");
  new Modules::SphereMesh(*this, "SphereMesh");
}

} // namespace Logic
} // namespace ART