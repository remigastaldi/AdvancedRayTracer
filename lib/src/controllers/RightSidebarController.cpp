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

void RightSidebarController::render() {
  Q_EMIT renderUpdate();
}

void RightSidebarController::scale() {
  Q_EMIT scaleUpdate();
}

} // namespace Controllers
} // namespace ART
