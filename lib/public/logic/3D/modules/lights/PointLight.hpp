#pragma once

#include "Light.hpp"
#include "Shape3D.hpp"

namespace ART::Logic::Modules::Lights {

class PointLight : public Light<Qt3DRender::QPointLight> {

public:
  PointLight(Shape3D &parent, std::string id) : Light<Qt3DRender::QPointLight>{parent, id} {
    get()->setColor("green");
    get()->setIntensity(1);
  }
};

} // namespace ART::Logic::Modules::Lights