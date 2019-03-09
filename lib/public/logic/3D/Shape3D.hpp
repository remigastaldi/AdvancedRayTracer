#pragma once

#include "globals.h"
#include "Entity.hpp"

#include <QEntity>
#include <Qt3DExtras>
#include <Qt3DRender>

#include <memory>

namespace ART {
namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT Shape3D : public Entity {
  Q_OBJECT
  Q_DISABLE_COPY(Shape3D)

public:
  Shape3D(std::string id, Qt3DCore::QEntity *parent);
  Qt3DCore::QEntity *_qEntity;

  Qt3DCore::QEntity *getQEntity() const noexcept;

public Q_SLOTS:
  void _mouseClicked(Qt3DRender::QPickEvent *pick);

Q_SIGNALS:
  void entitySelectedChanged(const std::string &id);
};

} // namespace Logic
} // namespace ART