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

float Transform3D::rotationX() { return _transform->rotationX(); }
float Transform3D::rotationY() { return _transform->rotationY(); }
float Transform3D::rotationZ() { return _transform->rotationZ(); }


Qt3DCore::QTransform *Transform3D::get() noexcept { return _transform; }

void Transform3D::setX(float x) noexcept {
  QVector3D trans{_transform->translation()};
  trans.setX(x);
  _transform->setTranslation(std::move(trans));
  Q_EMIT dataUpdate();
}

void Transform3D::setY(float y) noexcept {
  QVector3D trans{_transform->translation()};
  trans.setY(y);
  _transform->setTranslation(std::move(trans));
  Q_EMIT dataUpdate();
}

void Transform3D::setZ(float z) noexcept {
  QVector3D trans{_transform->translation()};
  trans.setZ(z);
  _transform->setTranslation(std::move(trans));
  Q_EMIT dataUpdate();
}


void Transform3D::setRotationX(float x) noexcept {
  _transform->setRotationX(x);
  Q_EMIT dataUpdate();
}

void Transform3D::setRotationY(float y) noexcept {
  _transform->setRotationY(y);
  Q_EMIT dataUpdate();
}

void Transform3D::setRotationZ(float z) noexcept {
  _transform->setRotationZ(z);
  Q_EMIT dataUpdate();
}
void Transform3D::setTransform(Qt3DCore::QTransform *transform) noexcept {
  transform->QObject::setParent(_parent.getQEntity());
  _transform = transform;
  Q_EMIT dataUpdate();
}

void Transform3D::setTranslation(QVector3D transform) noexcept {
  _transform->setTranslation(std::move(transform));
  Q_EMIT dataUpdate();
}

} // namespace Modules
} // namespace Logic
} // namespace ART