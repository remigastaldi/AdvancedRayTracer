#pragma once

#include "Entity.hpp"
#include "Module.hpp"
#include "Shape3D.hpp"

#include <Qt3DExtras>
#include <Qt3DRender>

namespace ART {
namespace Logic {
namespace Modules {

class Transform : public Entity, public Module<Qt3DCore::QTransform> {
public:
  Transform(Shape3D &parent, std::string id,
            Qt3DCore::QTransform *transform = new Qt3DCore::QTransform)
      : Entity{std::move(id)}, Module<Qt3DCore::QTransform>{transform}, _parent{parent} {
    Module<Qt3DCore::QTransform>::get()->setParent(&parent);
    parent.addComponent(Module<Qt3DCore::QTransform>::get());
    parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  }

  virtual ~Transform() {
    // std::cout << "DESTROY TRANSFORM" << std::endl;
    // _parent.removeChildren(Entity::id());
  }

private:
  Shape3D &_parent;
};

} // namespace Modules
} // namespace Logic
} // namespace ART