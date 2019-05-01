#pragma once

#include "globals.h"
#include "Global3D.hpp"

#include "Shape3D.hpp"

#include <memory>

namespace ART {
namespace Logic {

class Sphere : public Shape3D {

public:
  Sphere(std::string id, Qt3DCore::QEntity *parent);

  Type type() const noexcept {
    return Type::SPHERE;
  }

private:
};

} // namespace Logic
} // namespace ART