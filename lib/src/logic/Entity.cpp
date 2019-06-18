#include "Entity.hpp"
// #include  "ZIndex.hpp"

namespace ART {
namespace Logic {

Entity::Entity(std::string id) : _id{std::move(id)} {}

const std::string &Entity::id() const noexcept {
  return _id;
}

void Entity::setId(std::string id) noexcept {
  _id = std::move(id);
}

void Entity::addChildren(std::string id, std::unique_ptr<Entity> children) noexcept {
  _childrens.emplace(std::move(id), std::move(children));
}

void Entity::removeChildren(const std::string &id) noexcept {
  _childrens.erase(id);
}

const std::unordered_map<std::string, std::unique_ptr<Entity>> &Entity::childrens() const noexcept {
  return _childrens;
}


} // namespace Logic
} // namespace ART