#include "Transform3D.hpp"

namespace ART {
namespace Logic {
namespace Modules {

Transform3D::Transform3D(Shape3D &parent, std::string id, Qt3DCore::QTransform *transform)
    : Entity{std::move(id)}, _transform{transform}, _parent{parent} {
  _transform->setParent(parent.getQEntity());
  parent.getQEntity()->addComponent(_transform);
  parent.addChildren(Entity::id(), std::unique_ptr<Entity>(this));
}

Transform3D::~Transform3D() {
  _parent.getQEntity()->removeComponent(_transform);
  delete _transform;
}

float Transform3D::x() { return _transform->translation().x(); }

float Transform3D::y() { return _transform->translation().y(); }

float Transform3D::z() { return _transform->translation().z(); }

Qt3DCore::QTransform *Transform3D::get() noexcept { return _transform; }

void Transform3D::setX(float x) noexcept {
  QVector3D trans{_transform->translation()};
  trans.setX(x);
  _transform->setTranslation(std::move(trans));
}

void Transform3D::setY(float y) noexcept {
  QVector3D trans{_transform->translation()};
  trans.setY(y);
  _transform->setTranslation(std::move(trans));
}

void Transform3D::setZ(float y) noexcept {
  QVector3D trans{_transform->translation()};
  trans.setZ(y);
  _transform->setTranslation(std::move(trans));
}

} // namespace Modules
} // namespace Logic
} // namespace ART