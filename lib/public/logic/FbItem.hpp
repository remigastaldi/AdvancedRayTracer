#pragma once

#include <QtQuick/QQuickFramebufferObject>
#include <QtQuick/qquickitem.h>

#include "globals.h"

namespace ART {
namespace Models {
} // nameSpace Models

namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT FbItem : public QQuickFramebufferObject {
  Q_OBJECT
  Q_DISABLE_COPY(FbItem)

public:
  FbItem();
  ~FbItem() = default;
  FbItem(FbItem &&other) = delete;
  FbItem &operator=(FbItem &&other) = delete;

  QQuickFramebufferObject::Renderer *createRenderer() const noexcept override;

private:
  // qreal m_t;
  // Models::FbItemRenderer *m_renderer;
};

} // nameSpace Logic
} // namespace ART