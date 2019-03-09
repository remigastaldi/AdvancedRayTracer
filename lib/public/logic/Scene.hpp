#pragma once

#include "globals.h"

#include "Entity.hpp"

#include <QObject>

namespace ART {
namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT Scene : public QObject {
  Q_OBJECT

public:
  virtual ~Scene() {};

	virtual const std::unordered_map<std::string, std::unique_ptr<Entity>> &entities() const noexcept = 0;
	virtual Entity *selectedEntity() const noexcept = 0;
  virtual void selectEntity(const std::string & id) noexcept = 0;
  virtual void update() noexcept {};

Q_SIGNALS:
  void sceneUpdate();
  void selectedShapeUpdate();
};

} // namespace Logic
} // namespace ART