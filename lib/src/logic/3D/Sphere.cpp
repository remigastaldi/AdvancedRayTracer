#include "Sphere.hpp"
#include "MaterialPicker.hpp"
#include "SphereMesh.hpp"

namespace ART {
namespace Logic {

Sphere::Sphere(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
 new Modules::MaterialPicker(*this, "MaterialPicker");
  new Modules::SphereMesh(*this, "SphereMesh");
}

} // namespace Logic
} // namespace ART