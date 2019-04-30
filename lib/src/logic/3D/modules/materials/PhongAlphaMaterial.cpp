#include "PhongAlphaMaterial.hpp"

namespace ART {
namespace Logic {
namespace Modules {

PhongAlphaMaterial::PhongAlphaMaterial(Shape3D &parent, std::string id)
    : Material<Qt3DExtras::QPhongAlphaMaterial>{parent, id} {
  get()->setDiffuse(QColor(128, 128, 128));
  get()->setSpecular(QColor(255, 255, 255));
  get()->setAmbient(QColor(255, 255, 255));
}

float PhongAlphaMaterial::alpha() { return get()->alpha(); }
float PhongAlphaMaterial::shininess() { return get()->shininess(); }

QColor PhongAlphaMaterial::diffuse() { return get()->diffuse(); }
QColor PhongAlphaMaterial::specular() { return get()->specular(); }
QColor PhongAlphaMaterial::ambient() { return get()->ambient(); }

void PhongAlphaMaterial::setAlpha(float alpha) noexcept { get()->setAlpha(alpha); }
void PhongAlphaMaterial::setShininess(float shininess) noexcept { get()->setShininess(shininess); }
void PhongAlphaMaterial::setDiffuse(const QColor &color) noexcept { get()->setDiffuse(color); }
void PhongAlphaMaterial::setAmbient(const QColor &color) noexcept { get()->setAmbient(color); }
void PhongAlphaMaterial::setSpecular(const QColor &color) noexcept { get()->setSpecular(color); }
PhongAlphaMaterial::~PhongAlphaMaterial() {}

} // namespace Modules
} // namespace Logic
} // namespace ART