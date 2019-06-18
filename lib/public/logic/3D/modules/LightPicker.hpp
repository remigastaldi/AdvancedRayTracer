#pragma once

#include "Entity.hpp"
#include "Shape3D.hpp"

#include <Qt3DExtras>
#include <Qt3DRender>
#include <array>

namespace ART {
namespace Logic {
namespace Modules {
class LightPicker : public Entity {
  Q_OBJECT
  Q_PROPERTY(QStringList lights READ lights NOTIFY dataUpdate)
  Q_PROPERTY(int lightSelected READ lightSelected NOTIFY dataUpdate)
  Q_DISABLE_COPY(LightPicker)
public:
  LightPicker(Shape3D &parent, std::string id);
  virtual ~LightPicker();

  const QStringList lights();
  int lightSelected();

public Q_SLOTS:
  void pickLight(const QString &lightName);

Q_SIGNALS:
  void dataUpdate();

private:
  Shape3D &_parent;

  QString _lightSelected;
};
} // namespace Modules
} // namespace Logic
} // namespace ART