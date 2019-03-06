#include "Outliner.hpp"

namespace ART {
namespace Models {

Outliner::Outliner() {
}

void Outliner::setShapesHierarchy(const std::unordered_map<std::string, std::unique_ptr<Logic::Entity>> &shapes) noexcept {
  _shapes.clear();
  // _shapes.resize(shapes.size());
  // auto test(Logic::Entity((shapes.begin()->second)->id());
  for (const auto & [ key, value ] : shapes) {
    // _shapes.emplace_back();
  }
}

// const std::vector<std::string> &Outliner::shapesHierarchy() const noexcept {
  // return _shapes;
// }

}
} // namespace ART