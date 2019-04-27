#include "PhongMaterial.hpp"

namespace ART {
namespace Logic {
namespace Modules {

PhongMaterial::PhongMaterial(Shape3D &parent, std::string id, Qt3DExtras::QPhongMaterial *material)
    : Material<Qt3DExtras::QPhongMaterial>{parent, id, material} {
  material->setDiffuse(QColor(255, 255, 255, 125));
  material->setSpecular(QColor(255, 255, 255));
  material->setAmbient(QColor(255, 255, 255));
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