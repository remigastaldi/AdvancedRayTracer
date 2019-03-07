#pragma once

#include <QEntity>

namespace ART {
namespace Logic {

class RootEntity : public Qt3DCore::QEntity {
  Q_OBJECT
  Q_DISABLE_COPY(RootEntity)

public:
  explicit RootEntity(Qt3DCore::QEntity *parent = 0);
};

} // namespace Logic
} // namespace ART