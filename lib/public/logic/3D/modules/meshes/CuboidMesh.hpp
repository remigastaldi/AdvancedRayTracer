#pragma once

#include "Entity.hpp"
#include "Mesh.hpp"
#include "Shape3D.hpp"

#include <Qt3DExtras>
#include <Qt3DRender>

namespace ART::Logic::Modules {

class CuboidMesh : public Mesh<Qt3DExtras::QCuboidMesh> {
  Q_OBJECT
  Q_PROPERTY(float xExtent READ xExtent NOTIFY dataUpdate)
  Q_PROPERTY(float yExtent READ yExtent NOTIFY dataUpdate)
  Q_PROPERTY(float zExtent READ zExtent NOTIFY dataUpdate)
  Q_PROPERTY(QSize xyMeshResolution READ xyMeshResolution NOTIFY dataUpdate)
  Q_PROPERTY(QSize xzMeshResolution READ xzMeshResolution NOTIFY dataUpdate)
  Q_PROPERTY(QSize yzMeshResolution READ yzMeshResolution NOTIFY dataUpdate)
  Q_DISABLE_COPY(CuboidMesh)
public:
  CuboidMesh(Shape3D &parent, std::string id, Qt3DExtras::QCuboidMesh *mesh = new Qt3DExtras::QCuboidMesh);

  ~CuboidMesh() override;

  float xExtent();
  float yExtent();
  float zExtent();
  QSize xyMeshResolution();
  QSize xzMeshResolution();
  QSize yzMeshResolution();

public Q_SLOTS:
  void setXExtent(float xExtent) noexcept;
  void setYExtent(float yExtent) noexcept;
  void setZExtent(float zExtent) noexcept;
  void setXYMeshResolution(const QSize &resolution) noexcept;
  void setXZMeshResolution(const QSize &resolution) noexcept;
  void setYZMeshResolution(const QSize &resolution) noexcept;

Q_SIGNALS:
  void dataUpdate();

private:
};

} // namespace ART::Logic::Modules