#include "LightPicker.hpp"

#include "SpotLight.hpp"
#include "PointLight.hpp"

namespace ART::Logic::Modules {

LightPicker::LightPicker(Shape3D &parent, std::string id) : Entity{id}, _parent{parent} {
  parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  pickLight("PointLight");
}

LightPicker::~LightPicker() {}

void LightPicker::pickLight(const QString &lightName) {
  if (_lightSelected == lightName) {
    return;
  }
  _parent.removeChildren(_lightSelected.toStdString());
  if (lightName == "PointLight") {
    _lightSelected = "PointLight";
    new Lights::PointLight(_parent, "PointLight");
  } else if (lightName == "SpotLight") {
    _lightSelected = "SpotLight";
    new Lights::SpotLight(_parent, "SpotLight");
  }
}

int LightPicker::lightSelected() {
  return lights().indexOf(_lightSelected);
}

const QStringList LightPicker::lights() {
  QStringList list{{"PointLight", "SpotLight"}};
  return list;
}
} // namespace ART::Logic::Modules