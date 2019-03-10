#pragma once

#include "Entity.hpp"
#include "Shape3D.hpp"

#include <Qt3DExtras>
#include <Qt3DRender>

namespace ART {
namespace Logic {
namespace Modules {

class Transform3D : public Entity {
  Q_OBJECT
  Q_PROPERTY(float x READ x NOTIFY dataUpdate)
  Q_PROPERTY(float y READ y NOTIFY dataUpdate)
  Q_PROPERTY(float z READ z NOTIFY dataUpdate)

public:
  Transform3D(Shape3D &parent, std::string id, Qt3DCore::QTransform *transform = new Qt3DCore::QTransform);
  virtual ~Transform3D();

  float x();
  float y();
  float z();

  Qt3DCore::QTransform *get() noexcept;

  Qt3DCore::QTransform *operator->() { return _transform; };

public Q_SLOTS:
  void setX(float x) noexcept;
  void setY(float y) noexcept;
  void setZ(float z) noexcept;
  void setTranslation(Qt3DCore::QTransform *transform) noexcept;

Q_SIGNALS:
  void dataUpdate();

private:
  Shape3D &_parent;
  Qt3DCore::QTransform *_transform;
};

// Qt3DCore::QTransform * Transform::operator->() {
// return _transform;
// }

} // namespace Modules
} // namespace Logic
} // namespace ART