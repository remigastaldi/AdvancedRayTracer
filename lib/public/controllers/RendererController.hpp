#pragma once

#include <QtQuick/QQuickFramebufferObject>
#include <QtQuick/qquickitem.h>

#include "globals.h"

namespace ART {
namespace Models {
class RendererModel;
} // nameSpace Models

namespace Logic {} // nameSpace Logic

namespace Controllers {

class ADVANCED_RAY_TRACER_EXPORT RendererController : public QQuickFramebufferObject {
  Q_OBJECT
  Q_DISABLE_COPY(RendererController)

public:
  RendererController();
  ~RendererController() = default;
  RendererController(RendererController &&other) = delete;
  RendererController &operator=(RendererController &&other) = delete;

  QQuickFramebufferObject::Renderer *createRenderer() const noexcept override;

private:
  // qreal m_t;
  // Models::RendererModel *m_renderer;
};

} // namespace Controllers
} // namespace ART
