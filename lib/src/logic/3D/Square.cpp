#include "Square.hpp"
#include "Material.hpp"
#include "Mesh.hpp"

namespace ART {
namespace Logic {

Square::Square(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  new Modules::Material<>(*this, "Material");
  new Modules::Mesh<Qt3DExtras::QCuboidMesh>(*this, "Mesh");
}

} // namespace Logic
} // namespace ART