#pragma once

#include "globals.h"
#include "Global3D.hpp"

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

  Qt3DCore::QEntity *getQEntity() const noexcept;

  virtual Type type() const noexcept = 0;

public Q_SLOTS:
  void _mouseClicked(Qt3DRender::QPickEvent *pick);
  void _mouseMoved(Qt3DRender::QPickEvent *pick);

Q_SIGNALS:
  void entitySelectedChanged(const std::string &id);

private:
  Qt3DCore::QEntity *_qEntity;
  Qt3DRender::QObjectPicker *_mousePicker;
};

} // namespace Logic
} // namespace ART