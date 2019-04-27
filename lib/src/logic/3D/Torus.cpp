#include "Torus.hpp"
#include "Material.hpp"
#include "TorusMesh.hpp"

namespace ART {
namespace Logic {

Torus::Torus(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  new Modules::Material<Qt3DExtras::QMetalRoughMaterial>(*this, "Material");
  new Modules::TorusMesh(*this, "TorusMesh");
}

} // namespace Logic
} // namespace ART