#pragma once

#include <QString>
#include <QObject>
#include <QPointer>

#include "globals.h"

namespace ART {
  namespace Logic {
} // nameSpace Logic
namespace Models {

class ADVANCED_RAY_TRACER_EXPORT RightSidebarModel : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(RightSidebarModel)

public:
  explicit RightSidebarModel(QObject* parent = nullptr);

private:

Q_SIGNALS:
};

} // namespace Models
} // namespace ART
