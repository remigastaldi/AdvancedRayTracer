#include "LightEntity.hpp"

#include "Shape3D.hpp"
#include "PhongAlphaMaterial.hpp"
#include "LightPicker.hpp"

namespace ART {
namespace Logic {


LightEntity::LightEntity(std::string id, Qt3DCore::QEntity *parent) : Shape3D{std::move(id), parent} {
  new Modules::LightPicker(*this, "LightPicker");
}

} // namespace Logic
} // namespace ART