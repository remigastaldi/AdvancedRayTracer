#include "Torus.hpp"
#include "MaterialPicker.hpp"
#include "TorusMesh.hpp"

namespace ART {
namespace Logic {

Torus::Torus(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  new Modules::MaterialPicker(*this, "MaterialPicker");
  new Modules::TorusMesh(*this, "TorusMesh");
}

} // namespace Logic
} // namespace ART