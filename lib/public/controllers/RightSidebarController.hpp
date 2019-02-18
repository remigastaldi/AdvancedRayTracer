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

public Q_SLOTS:
  void render();
  void scale();

Q_SIGNALS:
  void renderUpdate();
  void scaleUpdate();
};

} // namespace Controllers
} // namespace ART
