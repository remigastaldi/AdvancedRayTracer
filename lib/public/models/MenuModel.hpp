#pragma once

#include <QString>
#include <QObject>
#include <QPointer>

#include "globals.h"

namespace ART {
  namespace Logic {
} // nameSpace Logic
namespace Models {

class ADVANCED_RAY_TRACER_EXPORT MenuModel : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MenuModel)

  Q_PROPERTY(bool isNewFile READ isNewFile NOTIFY isNewFileChanged)

public:
  explicit MenuModel(QObject* parent = nullptr);

  bool isNewFile() const;

Q_SIGNALS:
  void isNewFileChanged();
private:
};

} // namespace Models
} // namespace ART
