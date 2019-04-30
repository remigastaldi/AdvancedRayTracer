#pragma once

#include "Light.hpp"
#include "Shape3D.hpp"

namespace ART::Logic::Modules::Lights {

class SpotLight : public Light<Qt3DRender::QSpotLight> {

public:
  SpotLight(Shape3D &parent, std::string id)
      : Light<Qt3DRender::QSpotLight>{parent, id} {
    get()->setColor("green");
    get()->setIntensity(1);
    get()->setLocalDirection({0, 0, 1});
  }
};

} // namespace ART::Logic::Modules::Lights