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
  Q_PROPERTY(int materialSelected READ materialSelected NOTIFY dataUpdate)
  Q_DISABLE_COPY(MaterialPicker)
public:
  MaterialPicker(Shape3D &parent, std::string id);
  virtual ~MaterialPicker();

  const QStringList materials();
  int materialSelected();

public Q_SLOTS:
  void pickMaterial(const QString &materialName);

Q_SIGNALS:
  void dataUpdate();

private:
  Shape3D &_parent;

  QString _materialSelected;
};
} // namespace Modules
} // namespace Logic
} // namespace ART