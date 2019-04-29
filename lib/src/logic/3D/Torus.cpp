#include "Torus.hpp"
#include "MetalRoughMaterial.hpp"
#include "TorusMesh.hpp"

namespace ART {
namespace Logic {

Torus::Torus(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  new Modules::TorusMesh(*this, "TorusMesh");
}

} // namespace Logic
} // namespace ART