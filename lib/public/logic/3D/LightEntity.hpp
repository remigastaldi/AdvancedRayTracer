#pragma once

#include "globals.h"
#include "Global3D.hpp"

#include "Shape3D.hpp"
// #include <QEntity>
// #include <Qt3DExtras>
// #include <Qt3DRender>

#include <memory>

namespace ART {
namespace Logic {

class LightEntity : public Shape3D {

public:
  LightEntity(std::string id, Qt3DCore::QEntity *parent);

  Type type() const noexcept {
    return Type::LIGHT;
  }

private:
};

} // namespace Logic
} // namespace ART