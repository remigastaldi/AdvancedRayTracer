#include "Shape2D.hpp"
#include "Transform2D.hpp"

namespace ART {
namespace Logic {

Shape2D::Shape2D(std::string id) : Entity{std::move(id)} {
  new Modules::Transform2D(*this, "Transform2D");
  // new Modules::ZIndex(*this, Entity::id());
}

} // namespace Logic
} // namespace ART
