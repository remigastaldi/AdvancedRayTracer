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
  // Q_PROPERTY(float width READ width NOTIFY dataUpdate)
  // Q_PROPERTY(float height READ height NOTIFY dataUpdate)
  // Q_PROPERTY(float zExtent READ zExtent NOTIFY dataUpdate)
  // Q_PROPERTY(QSize xyMeshResolution READ xyMeshResolution NOTIFY dataUpdate)
  // Q_PROPERTY(QSize xzMeshResolution READ xzMeshResolution NOTIFY dataUpdate)
  // Q_PROPERTY(QSize yzMeshResolution READ yzMeshResolution NOTIFY dataUpdate)
  Q_DISABLE_COPY(PlaneMesh)

public:
  PlaneMesh(Shape3D &parent, std::string id, Qt3DExtras::QPlaneMesh *mesh = new Qt3DExtras::QPlaneMesh)
      : Mesh<Qt3DExtras::QPlaneMesh>{parent, id, mesh} {
    mesh->setWidth(100);
    mesh->setHeight(100);
  }

  // ~PlaneMesh() override;

  // float width() const noexcept;
  // float height() const noexcept;
  // float zExtent();
  // QSize xyMeshResolution();
  // QSize xzMeshResolution();
  // QSize yzMeshResolution();

public Q_SLOTS:
  // void setYExtent(float width) noexcept;
  // void setXExtent(float height) noexcept;
  // void setZExtent(float zExtent) noexcept;
  // void setXYMeshResolution(const QSize &resolution) noexcept;
  // void setXZMeshResolution(const QSize &resolution) noexcept;
  // void setYZMeshResolution(const QSize &resolution) noexcept;

Q_SIGNALS:
  void dataUpdate();

private:
};

} // namespace ART::Logic::Modules