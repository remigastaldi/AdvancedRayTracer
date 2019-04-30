#pragma once

#include "Entity.hpp"
#include "Shape3D.hpp"
#include "Mesh.hpp"

namespace ART::Logic::Modules {
template <typename T> class Light : public Entity {
public:
  Light(Shape3D &parent, std::string id, T *light = new T) : Entity{std::move(id)}, _light{light}, _parent{parent} {
    _light->setParent(parent.getQEntity());
    parent.getQEntity()->addComponent(_light);
    parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  };

  ~Light() override {
    _parent.getQEntity()->removeComponent(_light);
    delete _light;
  }

  T * get() {
    return _light;
  }

private:
  Shape3D &_parent;
  T *_light;
};
} // namespace ART::Logic::Modules