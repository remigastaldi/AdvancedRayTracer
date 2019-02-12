#pragma once

#include <QObject>
#include <QString>

#include "globals.h"

namespace ART {
namespace Models {
  class RightSidebarModel;
} // namespace Models

namespace Controllers {

class ADVANCED_RAY_TRACER_EXPORT RightSidebarController : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(RightSidebarController)

public:
  explicit RightSidebarController(QObject* parent = nullptr);
  ~RightSidebarController() = default;
  RightSidebarController(RightSidebarController&& other) = delete;
  RightSidebarController& operator=(RightSidebarController&& other) = delete;

  void setModel(ART::Models::RightSidebarModel* model);

private:
  ART::Models::RightSidebarModel *_model{nullptr};
  // QMetaObject::Connection document_created_connection_;

public Q_SLOTS:
  void render();

Q_SIGNALS:
  void renderUpdate();
};

} // namespace Controllers
} // namespace ART
