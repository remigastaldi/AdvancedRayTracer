#pragma once

#include "globals.h"

#include "Entity.hpp"
#include "Scene2D.hpp"
#include "Shape2D.hpp"
#include <QObject>

namespace ART {
namespace Logic {
namespace Modules {

class ADVANCED_RAY_TRACER_EXPORT ZIndex : public Entity {
  Q_OBJECT

public:
  ZIndex(Scene2D &scene, Shape2D &parent, std::string id)
      : Entity{std::move(id)}, _zIndex{0}, _scene{scene}, _parent{parent} {
    connect(this, &ZIndex::zIndexUpdate, &scene, &Scene2D::zIndexUpdate);
    parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
    scene.zIndexUpdate(parent.id());
  };

  virtual ~ZIndex() {
    Q_EMIT zIndexDelete(Entity::id());
  }

  void setIndex(size_t zIndex) noexcept {
    _zIndex = zIndex;
    Q_EMIT zIndexUpdate(_parent.id());
  }

  size_t zIndex() const noexcept { return _zIndex; }

private:
  size_t _zIndex;
  Scene2D &_scene;
  Shape2D &_parent;

Q_SIGNALS:
  void zIndexUpdate(const std::string &id);
  void zIndexDelete(const std::string &id);
};

} // namespace Modules
} // namespace Logic
} // namespace ART