#include "ZIndex.hpp"

#include "Entity.hpp"
#include "Scene2D.hpp"
#include "Shape2D.hpp"

namespace ART {
namespace Logic {
namespace Modules {

ZIndex::ZIndex(Scene2D &scene, Shape2D &parent, std::string id)
    : Entity{std::move(id)}, _zIndex{0}, _scene{scene}, _parent{parent} {
  connect(this, &ZIndex::zIndexUpdate, &scene, &Scene2D::zIndexUpdate);
  connect(this, &ZIndex::zIndexDelete, &scene, &Scene2D::zIndexDelete);
  parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
  scene.zIndexUpdate(0, parent.id());
};

ZIndex::~ZIndex() {
  Q_EMIT zIndexDelete(_zIndex, _parent.id());
  disconnect(this, &ZIndex::zIndexUpdate, &_scene, &Scene2D::zIndexUpdate);
  disconnect(this, &ZIndex::zIndexDelete, &_scene, &Scene2D::zIndexDelete);
}

void ZIndex::setIndex(int zIndex) noexcept {
  Q_EMIT zIndexDelete(_zIndex, _parent.id());
  _zIndex = zIndex;
  Q_EMIT zIndexUpdate(_zIndex, _parent.id());
  std::cout << "set zIndex" << std::endl;
}

int ZIndex::zIndex() const noexcept {
  return _zIndex;
}

} // namespace Modules
} // namespace Logic
} // namespace ART
