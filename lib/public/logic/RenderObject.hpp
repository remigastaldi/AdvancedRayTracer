#pragma once

#include <QMatrix>

#include "globals.h"

namespace ART {

namespace Logic {

class RenderObject {
 public:
  virtual void update(const QMatrix4x4 &) noexcept {};
};

} // namespace Logic
} // namespace ART