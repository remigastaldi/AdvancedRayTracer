#pragma once

#include "globals.h"
#include "Global3D.hpp"

#include "Shape3D.hpp"

#include <memory>

namespace ART {
namespace Logic {

class SceneLoader : public Shape3D {
public:
  SceneLoader(std::string id, Qt3DCore::QEntity *parent);

  Type type() const noexcept {
    return Type::SCENE_LOADER;
  }

private:
};

} // namespace Logic
} // namespace ART