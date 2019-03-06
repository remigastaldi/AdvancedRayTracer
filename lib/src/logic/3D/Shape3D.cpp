#include "Shape3D.hpp"
#include "Transform.hpp"

namespace ART {
namespace Logic {

Shape3D::Shape3D(std::string id, Qt3DCore::QEntity *parent)
    : Qt3DCore::QEntity{parent}, Entity{std::move(id)} {
  new Modules::Transform(*this, "Transform");
}

} // namespace Logic
} // namespace ART