#include "MaterialPicker.hpp"
#include "WireframeMaterial.hpp"

namespace ART::Logic::Modules {

MaterialPicker::MaterialPicker(Shape3D &parent, std::string id) : Entity{id}, _parent{parent} {
  parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  pickMaterial("WireframeMaterial");
}

MaterialPicker::~MaterialPicker() {}

void MaterialPicker::pickMaterial(const QString &materialName) {
  if (_materialSelected == materialName) {
    return;
  }
  _parent.removeChildren(_materialSelected.toStdString());
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
    _materialSelected = "WireframeMaterial";
    new WireframeMaterial(_parent, "WireframeMaterial");
  }
}

int MaterialPicker::materialSelected() {
  return materials().indexOf(_materialSelected);
}

const QStringList MaterialPicker::materials() {
  QStringList list{{"PhongAlphaMaterial", "MetalRoughMaterial", "PhongMaterial", "WireframeMaterial"}};
  return list;
}
} // namespace ART::Logic::Modules