#pragma once

#include "Entity.hpp"

#include <QObject>

namespace ART {
namespace Logic {

class Scene : public QObject {
public:
virtual ~Scene() {};
	virtual const std::unordered_map<std::string, std::unique_ptr<Entity>> &entities() const noexcept = 0;
};

} // namespace Logic
} // namespace ART