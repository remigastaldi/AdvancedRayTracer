#pragma once

#include <QString>
#include <QObject>
#include <QPointer>

#include "globals.h"

namespace ART {
  namespace Logic {
} // nameSpace Logic
namespace Models {

class ADVANCED_RAY_TRACER_EXPORT ToolbarModel : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(ToolbarModel)

  Q_PROPERTY(bool isNewFile READ isNewFile NOTIFY isNewFileChanged)

public:
  explicit ToolbarModel(QObject* parent = nullptr);

  bool isNewFile() const;

Q_SIGNALS:
  void isNewFileChanged();
private:
};

} // namespace Models
} // namespace ART
