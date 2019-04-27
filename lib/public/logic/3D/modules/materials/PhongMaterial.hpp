#pragma once

#include "Material.hpp"

namespace ART {
namespace Logic {
namespace Modules {

class PhongMaterial : public Material<Qt3DExtras::QPhongMaterial> {

public:
  PhongMaterial(Shape3D &parent, std::string id, Qt3DExtras::QPhongMaterial *mesh = new Qt3DExtras::QPhongMaterial);
  ~PhongMaterial() override;
};

} // namespace Modules
} // namespace Logic
} // namespace ART