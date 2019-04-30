#pragma once

#include "Entity.hpp"
#include "Mesh.hpp"
#include "Shape3D.hpp"
#include "Transform3D.hpp"

#include <Qt3DExtras>
#include <Qt3DRender>

namespace ART::Logic::Modules {

class PlaneMesh : public Mesh<Qt3DExtras::QPlaneMesh> {
  Q_OBJECT
  Q_PROPERTY(float width READ width NOTIFY dataUpdate)
  Q_PROPERTY(float height READ height NOTIFY dataUpdate)
  Q_DISABLE_COPY(PlaneMesh)

public:
  PlaneMesh(Shape3D &parent, std::string id, Qt3DExtras::QPlaneMesh *mesh = new Qt3DExtras::QPlaneMesh);  // ~PlaneMesh() override;

  float width() noexcept;
  float height() noexcept;

public Q_SLOTS:
  void setWidth(float width) noexcept;
  void setHeight(float height) noexcept;

Q_SIGNALS:
  void dataUpdate();

private:
};

} // namespace ART::Logic::Modules