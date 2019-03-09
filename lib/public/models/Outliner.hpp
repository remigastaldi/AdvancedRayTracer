#pragma once

#include "globals.h"
#include "Entity.hpp"

// #include <QObject>

#include <unordered_map>

namespace ART {
namespace Models {

class ADVANCED_RAY_TRACER_EXPORT Outliner {
public:
  void setEntities(const std::unique_ptr<Logic::Entity> &shape, std::string offsetString) noexcept;
  void setEntities(const std::unordered_map<std::string, std::unique_ptr<Logic::Entity>> &) noexcept;

  const std::vector<std::string> &entitiesHierarchy() const noexcept;
  virtual void setSelectionEntity(std::string id) noexcept;
  // virtual void setSelectionIndex(size_t index) noexcept;
  virtual size_t selectionIndex() const noexcept;

  virtual void dataUpdate() noexcept {};
  virtual void selectionIndexUpdate() noexcept {};

private:
  std::vector<std::string> _entitiesId;
  std::string _selectionEntity;
};

} // namespace Models
} // namespace ART