#include "PhongMaterial.hpp"

namespace ART {
namespace Logic {
namespace Modules {

PhongMaterial::PhongMaterial(Shape3D &parent, std::string id, Qt3DExtras::QPhongMaterial *material)
    : Material<Qt3DExtras::QPhongMaterial>{parent, id, material} {
  material->setDiffuse(QColor(255, 255, 255, 125));
  material->setSpecular(QColor(255, 255, 255));
//   material->setAmbient(QColor(255, 255, 255, 125));
}

PhongMaterial::~PhongMaterial() {}

} // namespace Modules
} // namespace Logic
} // namespace ART