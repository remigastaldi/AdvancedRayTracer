#pragma once

#include "globals.h"

#include "Entity.hpp"
#include "Shape2D.hpp"

#include <QObject>
#include <QBrush>

namespace ART {
namespace Logic {

namespace Modules {

class ADVANCED_RAY_TRACER_EXPORT Brush : public Entity {
  Q_OBJECT
  Q_PROPERTY(QString color READ color NOTIFY dataUpdate)


public:
  Brush(Shape2D &parent, std::string id);

  QString color();

  QBrush get();

public Q_SLOTS:
  void setColor(QString color);

private:
  QBrush _brush;

Q_SIGNALS:
  void dataUpdate();
};

} // namespace Modules
} // namespace Logic
} // namespace ART
