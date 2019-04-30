#pragma once

#include "Entity.hpp"
#include "Mesh.hpp"
#include "Shape3D.hpp"

#include <Qt3DExtras>
#include <Qt3DRender>

namespace ART::Logic::Modules {

class TorusMesh : public Mesh<Qt3DExtras::QTorusMesh> {
  Q_OBJECT
  Q_PROPERTY(float minorRadius READ minorRadius NOTIFY dataUpdate)
  Q_PROPERTY(float radius READ radius NOTIFY dataUpdate)
  Q_PROPERTY(int rings READ rings NOTIFY dataUpdate)
  Q_PROPERTY(int slices READ slices NOTIFY dataUpdate)
  Q_DISABLE_COPY(TorusMesh)
public:
  TorusMesh(Shape3D &parent, std::string id);

  ~TorusMesh() override;

  float minorRadius();
  float radius();
  int rings();
  int slices();

public Q_SLOTS:
  void setMinorRadius(float minorRadius) noexcept;
  void setRadius(float radius) noexcept;
  void setRings(int rings) noexcept;
  void setSlices(int slices) noexcept;

Q_SIGNALS:
  void dataUpdate();

private:
};

} // namespace ART::Logic::Modules