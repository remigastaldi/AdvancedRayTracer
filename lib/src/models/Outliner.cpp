#include "Outliner.hpp"

namespace ART {
namespace Models {

Outliner::Outliner() {
}

void Outliner::setEntities(const std::unique_ptr<Logic::Entity> &shape, std::string offsetString) noexcept {
  _entitiesId.emplace_back(offsetString + shape->id());
  offsetString += "|   ";
  for (auto &ent : shape->childrens()) {
    if (ent.first == "ZIndex")
      continue;
    _entitiesId.emplace_back(offsetString + ent.first);
    if (!ent.second->childrens().empty()) {
      setEntities(ent.second->childrens().begin()->second, offsetString + "|   ");
    }
  }
}

void Outliner::setEntities(const std::unordered_map<std::string, std::unique_ptr<Logic::Entity>> &shapes) noexcept {
  _entitiesId.clear();
  for (const auto & [ key, value ] : shapes) {
    if (key == "ZIndex")
      continue;
    if (!value->childrens().empty()) {
      setEntities(value, "");
    } else {
      _entitiesId.push_back(key);
    }
  }
}

const std::vector<std::string> &Outliner::entitiesHierarchy() const noexcept {
  return  _entitiesId;
}

// const std::vector<std::string> &Outliner::shapesHierarchy() const noexcept {
  // return _shapes;
// }

}
} // namespace ART