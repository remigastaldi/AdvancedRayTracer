#pragma once

#include <QObject>
#include <QString>

#include "globals.h"

namespace ART {
namespace Models {
  class SidebarModel;
} // namespace Models

namespace Controllers {

class ADVANCED_RAY_TRACER_EXPORT SidebarController : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(SidebarController)

public:
  explicit SidebarController(QObject* parent = nullptr);

  void setModel(ART::Models::SidebarModel* model);

private:
  ART::Models::SidebarModel *_model{nullptr};
  // QMetaObject::Connection document_created_connection_;

private Q_SLOTS:
};

} // namespace Controllers
} // namespace ART
