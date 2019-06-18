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

class Cuboid : public Shape3D {

public:
  Cuboid(std::string id, Qt3DCore::QEntity *parent);

  Type type() const noexcept {
    return Type::CUBE;
  }
private:
};
} // namespace Logic
} // namespace ART