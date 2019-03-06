#pragma once

#include "globals.h"
#include "Entity.hpp"

#include <unordered_map>

namespace ART {
namespace Models {

class ADVANCED_RAY_TRACER_EXPORT Outliner   {

public:
  Outliner();

  // void setShapesHierarchy(const std::unordered_map<std::string, std::unique_ptr<Logic::Entity>> &) noexcept;
  // const std::vector<Logic::Entity> &shapesHierarchy() const noexcept;

private:
  // std::vector<Logic::Entity> _shapes;
};

} // namespace Models
} // namespace ART