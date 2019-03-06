#pragma once

#include "Entity.hpp"
#include "Module.hpp"
#include "Shape3D.hpp"

#include <Qt3DExtras>
#include <Qt3DRender>

namespace ART {
namespace Logic {
namespace Modules {

template <typename T = Qt3DExtras::QSphereMesh> 
class Mesh : public Entity, public Module<T> {
public:
  Mesh(Shape3D &parent, std::string id, T *mesh = new T) : Entity{std::move(id)}, Module<T>{mesh}, _parent{parent} {
    Module<T>::get()->setParent(&parent);
    parent.addComponent(Module<T>::get());
    parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  };

  virtual ~Mesh() {
    // _parent.removeComponent(Module<T>::get());
    // std::cout << "DESTROY MESH" << std::endl;
  }

private:
  Shape3D &_parent;
};

} // namespace Modules
} // namespace Logic
} // namespace ART