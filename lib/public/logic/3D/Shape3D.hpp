#pragma once

#include "globals.h"
#include "Entity.hpp"

#include <QEntity>
#include <Qt3DExtras>
#include <Qt3DRender>

#include <memory>

namespace ART {
namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT Shape3D : public Qt3DCore::QEntity, public Entity {
  Q_OBJECT
  Q_DISABLE_COPY(Shape3D)

public:
  Shape3D(std::string id, Qt3DCore::QEntity *parent);
};

} // namespace Logic
} // namespace ART