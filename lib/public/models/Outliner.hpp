#pragma once

#include "globals.h"
#include "Entity.hpp"

#include <QObject>

#include <unordered_map>

namespace ART {
namespace Models {

class ADVANCED_RAY_TRACER_EXPORT Outliner {
public:
  Outliner();

  void setEntities(const std::unique_ptr<Logic::Entity> &shape, std::string offsetString) noexcept;
  void setEntities(const std::unordered_map<std::string, std::unique_ptr<Logic::Entity>> &) noexcept;

  const std::vector<std::string> &entitiesHierarchy() const noexcept;

  virtual void updateData() noexcept {};

private:
  std::vector<std::string> _entitiesId;
};

} // namespace Models
} // namespace ART