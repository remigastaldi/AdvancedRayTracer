#pragma once

#include "globals.h"

#include <QObject>
#include <QString>
#include <QVariantList>

#include <iostream>

namespace ART {
namespace Models {
  class RightSidebarModel;
} // namespace Models
namespace Logic {
  class Entity;
}
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
  // QVariantList test() {
  //   return QVariantList{"qwe", "Mesh", "zxc"};
  // }
  void render() noexcept;
  void deleteShape() noexcept;
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
