#pragma once

#include "Entity.hpp"
#include "Shape3D.hpp"

#include <Qt3DExtras>
#include <Qt3DRender>

namespace ART::Logic::Modules {

class Transform3D : public Entity {
  Q_OBJECT
  Q_PROPERTY(float x READ x NOTIFY dataUpdate)
  Q_PROPERTY(float y READ y NOTIFY dataUpdate)
  Q_PROPERTY(float z READ z NOTIFY dataUpdate)
  Q_PROPERTY(float rotationX READ rotationX NOTIFY dataUpdate)
  Q_PROPERTY(float rotationY READ rotationY NOTIFY dataUpdate)
  Q_PROPERTY(float rotationZ READ rotationZ NOTIFY dataUpdate)
  Q_DISABLE_COPY(Transform3D)

public:
  Transform3D(Shape3D &parent, std::string id, Qt3DCore::QTransform *transform = new Qt3DCore::QTransform);
  ~Transform3D() override;
  Transform3D(Transform3D&& other) = delete;
  Transform3D& operator=(Transform3D&& other) = delete;

  float x();
  float y();
  float z();

  float rotationX();
  float rotationY();
  float rotationZ();

  Qt3DCore::QTransform *get() noexcept;

public Q_SLOTS:
  void setX(float x) noexcept;
  void setY(float y) noexcept;
  void setZ(float z) noexcept;
  void setRotationX(float x) noexcept;
  void setRotationY(float y) noexcept;
  void setRotationZ(float z) noexcept;
  void setTransform(Qt3DCore::QTransform *transform) noexcept;
  void setTranslation(QVector3D transform) noexcept;

Q_SIGNALS:
  void dataUpdate();

private:
  Shape3D &_parent;
  Qt3DCore::QTransform *_transform;
};

// Qt3DCore::QTransform * Transform::operator->() {
// return _transform;
// }

} // namespace ART::Logic::Modules