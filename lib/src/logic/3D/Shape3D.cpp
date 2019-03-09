#include "Shape3D.hpp"
#include "Transform3D.hpp"
#include <iostream>

namespace ART {
namespace Logic {

Shape3D::Shape3D(std::string id, Qt3DCore::QEntity *parent)
   : Entity{std::move(id)} , _qEntity{new Qt3DCore::QEntity{parent}} {
  new Modules::Transform3D(*this, "Transform3D");
  auto *event = new Qt3DRender::QObjectPicker{_qEntity};
  _qEntity->addComponent(event);
  connect(event, &Qt3DRender::QObjectPicker::clicked, this, &Shape3D::_mouseClicked);
}

Qt3DCore::QEntity *Shape3D::getQEntity() const noexcept {
  return _qEntity;
}

void Shape3D::_mouseClicked(Qt3DRender::QPickEvent *pick) {
  (void) pick;
  Q_EMIT entitySelectedChanged(Entity::id());
}

} // namespace Logic
} // namespace ART