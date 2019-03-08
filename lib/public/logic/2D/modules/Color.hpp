#pragma once

#include "globals.h"

#include "Entity.hpp"

#include <QObject>

namespace ART {
namespace Logic {
class Scene2D;
class Shape2D;

namespace Modules {

class ADVANCED_RAY_TRACER_EXPORT Color : public Entity {
  Q_OBJECT
public:
  Color(std::string id) : Entity{std::move(id)}{}
};

} // namespace Modules
} // namespace Logic
} // namespace ART
