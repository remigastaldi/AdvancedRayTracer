#pragma once

#include "Entity.hpp"
#include "MetalRoughMaterial.hpp"
#include "PhongAlphaMaterial.hpp"
#include "PhongMaterial.hpp"
#include "Shape3D.hpp"

#include <Qt3DExtras>
#include <Qt3DRender>
#include <array>

namespace ART {
namespace Logic {
namespace Modules {
class MaterialPicker : public Entity {
  Q_OBJECT
  Q_PROPERTY(QStringList materials READ materials NOTIFY dataUpdate)
  Q_DISABLE_COPY(MaterialPicker)
public:
  MaterialPicker(Shape3D &parent, std::string id) : Entity{id}, _parent{parent} {
    parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  };
  virtual ~MaterialPicker(){};

  const QStringList materials() {
    QStringList list{{"PhongAlphaMaterial", "MetalRoughMaterial", "PhongMaterial", "WireframeMaterial"}};
    return list;
  };

public Q_SLOTS:
  void pickMaterial(const QString &materialName) {

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

Q_SIGNALS:
  void dataUpdate();

private:
  Shape3D &_parent;

  std::string _materialSelected = "PhongAlphaMaterial";
};
} // namespace Modules
} // namespace Logic
} // namespace ART