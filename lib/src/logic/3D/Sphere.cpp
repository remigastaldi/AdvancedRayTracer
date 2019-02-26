#include "Sphere.hpp"

namespace ART {
namespace Logic {

Sphere::Sphere(Qt3DCore::QEntity *parent)
  : Shape3D{parent, std::make_shared<Qt3DExtras::QSphereMesh>(),
  std::make_shared<Qt3DExtras::QDiffuseSpecularMaterial>()}
{}

} // namespace Logic
} // namespace ART