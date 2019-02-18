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
  void render() noexcept;
  void deleteShape()noexcept;
  void setAutoRenderRate(int rate) noexcept;
  void createCube() noexcept;

Q_SIGNALS:
  void renderUpdate();
  void deleteShapeUpdate();
  void renderRateUpdate(int rate);
  void createCubeEvent();
};

} // namespace Controllers
} // namespace ART
