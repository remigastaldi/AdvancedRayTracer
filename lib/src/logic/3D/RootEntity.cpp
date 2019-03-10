#include "RootEntity.hpp"

namespace ART {
namespace Logic {

RootEntity::RootEntity(Qt3DCore::QEntity *parent) : Qt3DCore::QEntity{parent} {
}

void RootEntity::keyPressedEvent(Qt::Key event) {
  qInfo() << event;
}

} // namespace Logic
} // namespace ART