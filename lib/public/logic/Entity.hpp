#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

namespace ART {
namespace Logic {

class Entity {
public:
  explicit Entity(std::string id);
  virtual ~Entity() = default;
  Entity(const Entity& other) = delete;
  Entity(Entity&& other) = delete;
  Entity& operator=(const Entity& other) = delete;
  Entity& operator=(Entity&& other) = delete;

  template <typename T>
  T &module(const std::string &id) const {
    return dynamic_cast<T &>(*(_childrens.at(id).get()));
  }

  const std::string &id() const noexcept;
  void setId(std::string id) noexcept;

  void addChildren(std::string id, std::unique_ptr<Entity> children) noexcept;
  void removeChildren(const std::string &id) noexcept;
  const std::unordered_map<std::string, std::unique_ptr<Entity>> &childrens() const noexcept;

private:
  std::string _id;
  std::unordered_map<std::string, std::unique_ptr<Entity>> _childrens;
};

} // namespace Logic
} // namespace ART