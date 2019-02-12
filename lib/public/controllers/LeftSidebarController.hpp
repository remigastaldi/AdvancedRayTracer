#pragma once

#include <QObject>
#include <QString>

#include "globals.h"

namespace ART {
namespace Models {
  class LeftSidebarModel;
} // namespace Models

namespace Controllers {

class ADVANCED_RAY_TRACER_EXPORT LeftSidebarController : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(LeftSidebarController)

public:
  explicit LeftSidebarController(QObject* parent = nullptr);
  ~LeftSidebarController() = default;
  LeftSidebarController(LeftSidebarController&& other) = delete;
  LeftSidebarController& operator=(LeftSidebarController&& other) = delete;

  void setModel(ART::Models::LeftSidebarModel* model);

private:
  ART::Models::LeftSidebarModel *_model{nullptr};
  // QMetaObject::Connection document_created_connection_;

private Q_SLOTS:
};

} // namespace Controllers
} // namespace ART
