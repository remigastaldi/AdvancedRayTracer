#pragma once

#include "globals.h"

#include "Shape3D.hpp"

#include <memory>

namespace ART {
namespace Logic {
class Object3D : public Shape3D {
public:
  Object3D(std::string id, Qt3DCore::QEntity *parent);

private:
};
} // namespace Logic
} // namespace ART