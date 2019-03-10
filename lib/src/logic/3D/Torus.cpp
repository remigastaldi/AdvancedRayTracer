#include "Torus.hpp"
#include "Material.hpp"
#include "Mesh.hpp"

namespace ART {
namespace Logic {

Torus::Torus(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  new Modules::Material<>(*this, "Material");
  new Modules::Mesh<Qt3DExtras::QTorusMesh>(*this, "Mesh");
}

} // namespace Logic
} // namespace ART