#include "ToolbarController.hpp"
#include "ToolbarModel.hpp"

namespace ART {
namespace Controllers {

ToolbarController::ToolbarController(QObject* parent)
  : QObject{parent}
{}

void ToolbarController::setModel(ART::Models::ToolbarModel* model) {
  _model = model;
  if (_model == nullptr) {
    return;
  }
  _model->setParent(this);
}

} // namespace Controllers
} // namespace ART
