#pragma once

#include "globals.h"
#include "Global3D.hpp"

#include "Shape3D.hpp"

#include <memory>

namespace ART {
namespace Logic {

class Torus : public Shape3D {

public:
  Torus(std::string id, Qt3DCore::QEntity *parent);

  Type type() const noexcept {
    return Type::TORUS;
  }

private:
};

} // namespace Logic
} // namespace ART