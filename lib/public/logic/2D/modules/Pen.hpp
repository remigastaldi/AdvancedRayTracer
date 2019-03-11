#pragma once

#include "globals.h"

#include "Entity.hpp"
#include "Shape2D.hpp"

#include <QObject>
#include <QPen>

namespace ART {
namespace Logic {

namespace Modules {

class ADVANCED_RAY_TRACER_EXPORT Pen : public Entity {
  Q_OBJECT
  Q_PROPERTY(QString color READ color NOTIFY dataUpdate)
  // Q_PROPERTY(QString width READ width NOTIFY dataUpdate)

public:
  Pen(Shape2D &parent, std::string id);

  QString color();
  QPen get();

public Q_SLOTS:
  double width();
  void setColor(const QString &color);
  void setWidth(double Width);

Q_SIGNALS:
  void dataUpdate();

private:
  QPen _pen;
};

} // namespace Modules
} // namespace Logic
} // namespace ART
