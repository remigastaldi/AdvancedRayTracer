#pragma once

#include "globals.h"

#include "Shape3D.hpp"

#include <memory>

namespace ART {
namespace Logic {
class SceneLoader : public Shape3D {
public:
  SceneLoader(std::string id, Qt3DCore::QEntity *parent);

private:
};
} // namespace Logic
} // namespace ART