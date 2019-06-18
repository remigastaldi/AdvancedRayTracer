#pragma once

#include "Entity.hpp"
#include "Shape3D.hpp"

#include <QEntity>
#include <QRect>
#include <Qt3DExtras>
#include <Qt3DRender>

namespace ART {
namespace Logic {
namespace Modules {

template <typename T> class Material : public Entity {
public:
  Material(Shape3D &parent, std::string id, T *material = new T)
      : Entity{std::move(id)}, _material{material}, _parent{parent} {
    _material->setParent(parent.getQEntity());
    _parent.getQEntity()->addComponent(_material);
    _parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  }

  ~Material() override {
    _parent.getQEntity()->removeComponent(_material);
    delete _material;
  }
  
  T *get() noexcept { return _material; }

  Shape3D &getShape() noexcept { return _parent; }

private:
  Shape3D &_parent;
  T *_material;
};

} // namespace Modules
} // namespace Logic
} // namespace ART