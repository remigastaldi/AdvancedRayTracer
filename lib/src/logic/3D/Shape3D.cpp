#include "Shape3D.hpp"
#include "MaterialPicker.hpp"
#include "Transform3D.hpp"
#include <iostream>

namespace ART {
namespace Logic {

Shape3D::Shape3D(std::string id, Qt3DCore::QEntity *parent)
   : Entity{std::move(id)} , _qEntity{new Qt3DCore::QEntity{parent}} {
  new Modules::Transform3D(*this, "Transform3D");
  _mousePicker = new Qt3DRender::QObjectPicker{_qEntity};
  _qEntity->addComponent(_mousePicker);
  connect(_mousePicker, &Qt3DRender::QObjectPicker::clicked, this, &Shape3D::_mouseClicked);
  connect(_mousePicker, &Qt3DRender::QObjectPicker::moved, this, &Shape3D::_mouseMoved);
}

Qt3DCore::QEntity *Shape3D::getQEntity() const noexcept {
  return _qEntity;
}

void Shape3D::_mouseClicked(Qt3DRender::QPickEvent *pick) {
  (void) pick;
  _mousePicker->setDragEnabled(true);
  Q_EMIT entitySelectedChanged(Entity::id());
}

void Shape3D::_mouseMoved(Qt3DRender::QPickEvent *pick) {
  (void) pick;
  // qInfo() << pick->position();
}

} // namespace Logic
} // namespace ART