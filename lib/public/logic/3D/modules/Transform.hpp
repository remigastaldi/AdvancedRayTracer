#pragma once

#include "Entity.hpp"
#include "Shape3D.hpp"

#include <Qt3DExtras>
#include <Qt3DRender>

namespace ART {
namespace Logic {
namespace Modules {

class Transform : public Entity  {
public:
  Transform(Shape3D &parent, std::string id,
            Qt3DCore::QTransform *transform = new Qt3DCore::QTransform)
      : Entity{std::move(id)}, _transform{transform}, _parent{parent} {
    _transform->setParent(&parent);
    parent.addComponent(_transform);
    parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  }

  virtual ~Transform() {
    _parent.removeComponent(_transform);
    delete _transform;
  }

  Qt3DCore::QTransform *get() noexcept { return _transform; }
  Qt3DCore::QTransform * operator->() {
    return _transform;
  };

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