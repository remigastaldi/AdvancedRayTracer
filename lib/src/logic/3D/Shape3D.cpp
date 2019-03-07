#include "Shape3D.hpp"
#include "Transform.hpp"

namespace ART {
namespace Logic {

Shape3D::Shape3D(std::string id, Qt3DCore::QEntity *parent)
    // : Qt3DCore::QEntity{parent}, 
   : Entity{std::move(id)} , _qEntity{parent} {
  new Modules::Transform(*this, "Transform");
}

Qt3DCore::QEntity *Shape3D::getQEntity() const noexcept {
  return _qEntity;
}

} // namespace Logic
} // namespace ART