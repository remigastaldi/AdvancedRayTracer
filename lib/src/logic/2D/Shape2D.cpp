#include "Shape2D.hpp"
#include "ZIndex.hpp"

namespace ART {
namespace Logic {

Shape2D::Shape2D(std::string id) : Entity{std::move(id)} {
  // new Modules::ZIndex(*this, Entity::id());
}

} // namespace Logic
} // namespace ART
