#include "MaterialPicker.hpp"

namespace ART::Logic::Modules {

MaterialPicker::MaterialPicker(Shape3D &parent, std::string id) : Entity{id}, _parent{parent} {
  parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
}

MaterialPicker::~MaterialPicker() {}

void MaterialPicker::pickMaterial(const QString &materialName) {
  _parent.removeChildren(_materialSelected);
  if (materialName == "MetalRoughMaterial") {
    _materialSelected = "MetalRoughMaterial";
    new MetalRoughMaterial(_parent, "MetalRoughMaterial");
  } else if (materialName == "PhongAlphaMaterial") {
    _materialSelected = "PhongAlphaMaterial";
    new PhongAlphaMaterial(_parent, "PhongAlphaMaterial");
  } else if (materialName == "PhongMaterial") {
    _materialSelected = "PhongMaterial";
    new PhongMaterial(_parent, "PhongMaterial");
  } else if (materialName == "WireframeMaterial") {
  }
}

const QStringList MaterialPicker::materials() {
  QStringList list{{"PhongAlphaMaterial", "MetalRoughMaterial", "PhongMaterial", "WireframeMaterial"}};
  return list;
}
} // namespace ART::Logic::Modules