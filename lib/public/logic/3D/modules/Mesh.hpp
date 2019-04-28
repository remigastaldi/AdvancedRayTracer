#pragma once

#include "Entity.hpp"
#include "Shape3D.hpp"

#include <Qt3DExtras>
#include <Qt3DRender>

namespace ART {
namespace Logic {
namespace Modules {

template <typename T>
class Mesh : public Entity {
public:
  Mesh(Shape3D &parent, std::string id, T *mesh = new T) : Entity{std::move(id)}, _mesh{mesh}, _parent{parent} {
    _mesh->setParent(parent.getQEntity());
    parent.getQEntity()->addComponent(_mesh);
    parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  };

  virtual ~Mesh() {
    _parent.getQEntity()->removeComponent(_mesh);
    delete _mesh;
  }

  T *get() noexcept { return _mesh; }

private:
  Shape3D &_parent;
  T *_mesh;
};

} // namespace Modules
} // namespace Logic
} // namespace ART