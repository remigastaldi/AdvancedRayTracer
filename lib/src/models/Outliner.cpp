#include "Outliner.hpp"

namespace ART {
namespace Models {

void Outliner::setEntities(const std::unique_ptr<Logic::Entity> &shape, std::string offsetString) noexcept {
  _entitiesId.emplace_back(offsetString + shape->id());
  offsetString += "|   ";
  for (auto &ent : shape->childrens()) {
    if (ent.first == "ZIndex" || ent.first == "Transform2D")
      continue;
    _entitiesId.emplace_back(offsetString + ent.first);
    if (!ent.second->childrens().empty()) {
      setEntities(ent.second->childrens().begin()->second, offsetString + "|   ");
    }
  }
}

void Outliner::setEntities(const std::unordered_map<std::string, std::unique_ptr<Logic::Entity>> &shapes) noexcept {
  _entitiesId.clear();
  for (const auto &[key, value] : shapes) {
    if (key == "ZIndex" || key == "Transform2D")
      continue;
    if (!value->childrens().empty()) {
      setEntities(value, "");
    } else {
      _entitiesId.push_back(key);
    }
  }
}

// void Outliner::setSelectionIndex(size_t index) noexcept {
//   _selectionEntity = _entitiesId.at(index);
// }

size_t  Outliner::selectionIndex() const noexcept {
  for (size_t i = 0; i < _entitiesId.size(); ++i) {
    if (_entitiesId[i] == _selectionEntity) {
      return i;
    }
  }
  return 0;
}

const std::vector<std::string> &Outliner::entitiesHierarchy() const noexcept { return _entitiesId; }

void Outliner::setSelectionEntity(std::string id) noexcept {
  _selectionEntity = std::move(id);
  selectionIndexUpdate();
}

} // namespace Models
} // namespace ART