#pragma once

#include "Entity.hpp"
#include "Mesh.hpp"
#include "Shape3D.hpp"

#include <Qt3DExtras>
#include <Qt3DRender>

namespace ART::Logic::Modules {

class ConeMesh : public Mesh<Qt3DExtras::QConeMesh> {
  Q_OBJECT
  Q_PROPERTY(float length READ length NOTIFY dataUpdate)
  Q_PROPERTY(float topRadius READ topRadius NOTIFY dataUpdate)
  Q_PROPERTY(float bottomRadius READ bottomRadius NOTIFY dataUpdate)
  Q_PROPERTY(int rings READ rings NOTIFY dataUpdate)
  Q_PROPERTY(int slices READ slices NOTIFY dataUpdate)
  Q_DISABLE_COPY(ConeMesh)
public:
  ConeMesh(Shape3D &parent, std::string id);

  ~ConeMesh() override;

  float length();
  float topRadius();

  float bottomRadius();
  int rings();
  int slices();

public Q_SLOTS:
  void setLength(float length) noexcept;
  void setTopRadius(float radius) noexcept;
  void setBottomRadius(float radius) noexcept;
  void setRings(int rings) noexcept;
  void setSlices(int slices) noexcept;

Q_SIGNALS:
  void dataUpdate();

private:
};

} // namespace ART::Logic::Modules