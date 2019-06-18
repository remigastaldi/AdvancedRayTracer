#include "RightSidebarController.hpp"
#include "RightSidebarModel.hpp"

#include <thread>
#include <iostream>

namespace ART {
namespace Controllers {

RightSidebarController::RightSidebarController(QObject *parent)
  : QObject{parent}
{}

void RightSidebarController::setModel(ART::Models::RightSidebarModel *model) {
  _model = model;
  if (_model == nullptr) {
    return;
  }
  _model->setParent(this);
}

void RightSidebarController::render() noexcept {
  Q_EMIT renderUpdate();
}

void RightSidebarController::deleteShape() noexcept {
  Q_EMIT deleteShapeUpdate();
  Q_EMIT renderUpdate();
}

void RightSidebarController::setAutoRenderRate(int rate) noexcept {
  Q_EMIT renderRateUpdate(rate);
  Q_EMIT renderUpdate();
}

void RightSidebarController::createCube() noexcept {
  Q_EMIT createCubeEvent();
  Q_EMIT renderUpdate();
}

} // namespace Controllers
} // namespace ART
