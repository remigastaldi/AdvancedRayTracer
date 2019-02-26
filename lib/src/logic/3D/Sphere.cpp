#include "Sphere.hpp"

namespace ART {
namespace Logic {

Sphere::Sphere(Qt3DCore::QEntity *parent)
  : Shape3D{parent, new Qt3DExtras::QSphereMesh,
  new Qt3DExtras::QDiffuseSpecularMaterial}
{}

} // namespace Logic
} // namespace ART