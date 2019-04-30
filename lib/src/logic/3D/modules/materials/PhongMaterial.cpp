#include "PhongMaterial.hpp"

namespace ART {
namespace Logic {
namespace Modules {

PhongMaterial::PhongMaterial(Shape3D &parent, std::string id)
    : Material<Qt3DExtras::QPhongMaterial>{parent, id} {
  get()->setDiffuse(QColor(128, 128, 128));
  get()->setSpecular(QColor(13, 106, 117));
  get()->setAmbient(QColor(95, 77, 165));
}

QColor PhongMaterial::diffuse() { return get()->diffuse(); }
QColor PhongMaterial::specular() { return get()->specular(); }
QColor PhongMaterial::ambient() { return get()->ambient(); }

void PhongMaterial::setDiffuse(const QColor &color) noexcept { get()->setDiffuse(color); }
void PhongMaterial::setAmbient(const QColor &color) noexcept { get()->setAmbient(color); }
void PhongMaterial::setSpecular(const QColor &color) noexcept { get()->setSpecular(color); }
PhongMaterial::~PhongMaterial() {}

} // namespace Modules
} // namespace Logic
} // namespace ART