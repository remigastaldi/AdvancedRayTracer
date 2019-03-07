#pragma once

#include "Entity.hpp"
#include "Shape3D.hpp"

#include <QEntity>
#include <Qt3DExtras>
#include <Qt3DRender>

namespace ART {
namespace Logic {
namespace Modules {

template <typename T = Qt3DExtras::QDiffuseSpecularMaterial>
class Material : public Entity {
public:
  Material(Shape3D &parent, std::string id, T *material = new T)
      : Entity{std::move(id)}, _material{material}, _parent{parent} {
    _material->setParent(parent.getQEntity());
    _parent.getQEntity()->addComponent(_material);
    _parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  };

  virtual ~Material() {
    _parent.getQEntity()->removeComponent(_material);
    delete _material;
  }

  T *get() noexcept { return _material; }
  T * operator->();

private:
  Shape3D &_parent;
  T *_material;
};

template <typename T>
T * Material<T>::operator->() {
  return _material;
}

} // namespace Modules
} // namespace Logic
} // namespace ART