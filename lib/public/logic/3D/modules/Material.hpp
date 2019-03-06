#pragma once

#include "Entity.hpp"
#include "Module.hpp"
#include "Shape3D.hpp"

#include <QEntity>
#include <Qt3DExtras>
#include <Qt3DRender>

namespace ART {
namespace Logic {
namespace Modules {

template <typename T = Qt3DExtras::QDiffuseSpecularMaterial>
class Material : public Entity, public Module<T> {
public:
  Material(Shape3D &parent, std::string id, T *material = new T)
      : Entity{std::move(id)}, Module<T>{material}, _parent{parent} {
    Module<T>::get()->setParent(&parent);
    _parent.addComponent(Module<T>::get());
    _parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  };

  virtual ~Material() {
    // std::cout << "DESTROY MATERIAL" << std::endl;
    // _parent.removeComponent(Module<T>::get());
  }

private:
  Shape3D &_parent;
};

} // namespace Modules
} // namespace Logic
} // namespace ART