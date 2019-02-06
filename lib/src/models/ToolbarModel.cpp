#include "ToolbarModel.hpp"

namespace ART {
namespace Models {

ToolbarModel::ToolbarModel(QObject* parent) : QObject{parent} {
}

bool ToolbarModel::isNewFile() const {
  return true;
}

} //namespace Models
} //namespace ART
