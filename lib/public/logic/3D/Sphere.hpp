#pragma once

#include "globals.h"

#include "Shape3D.hpp"
// #include <QEntity>
// #include <Qt3DExtras>
// #include <Qt3DRender>

#include <memory>

namespace ART {
namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT Sphere : public Shape3D {
  Q_OBJECT
  Q_DISABLE_COPY(Sphere)

public:
  Sphere(Qt3DCore::QEntity *parent);

private:
};
} // namespace Logic
} // namespace ART