#include "MetalRoughMaterial.hpp"

namespace ART::Logic::Modules {

MetalRoughMaterial::MetalRoughMaterial(Shape3D &parent, std::string id)
    : Material<Qt3DExtras::QMetalRoughMaterial>{parent, id} {
  get()->setBaseColor(QColor(125, 125, 125));
  get()->setRoughness(0.10);
  get()->setMetalness(0.95);
}
MetalRoughMaterial::~MetalRoughMaterial() {}

} // namespace ART::Logic::Modules