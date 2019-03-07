#pragma once

#include "globals.h"

#include <QEntity>

namespace ART {
namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT RootEntity : public Qt3DCore::QEntity {
  Q_OBJECT
  Q_DISABLE_COPY(RootEntity)

public:
  explicit RootEntity(Qt3DCore::QEntity *parent = 0);
};

} // namespace Logic
} // namespace ART