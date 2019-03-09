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
  Transform3D(Shape3D &parent, std::string id,
            Qt3DCore::QTransform *transform = new Qt3DCore::QTransform)
      : Entity{std::move(id)}, _transform{transform}, _parent{parent} {
    _transform->setParent(parent.getQEntity());
    parent.getQEntity()->addComponent(_transform);
    parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  }

  virtual ~Transform3D() {
    _parent.getQEntity()->removeComponent(_transform);
    delete _transform;
  }

  float x() {
    return _transform->translation().x();
  }

  float y() {
    return _transform->translation().x();
  }

  float z() {
    return _transform->translation().x();
  }

  Qt3DCore::QTransform *get() noexcept { return _transform; }
  
  Qt3DCore::QTransform *operator->() {
    return _transform;
  };

public Q_SLOTS:
  void setX(double x) noexcept {
    QVector3D trans{_transform->translation()};
    trans.setX(x);
    qInfo() << trans;
    _transform->setTranslation(std::move(trans));
  }

  void setY(double y) noexcept {
    QVector3D trans{_transform->translation()};
    trans.setY(y);
    _transform->setTranslation(std::move(trans));
  }

  void setZ(double y) noexcept {
    QVector3D trans{_transform->translation()};
    trans.setZ(y);
    _transform->setTranslation(std::move(trans));
  }

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