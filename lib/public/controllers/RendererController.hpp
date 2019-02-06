#pragma  once

#include <QtQuick/qquickitem.h>
#include <QtQuick/QQuickFramebufferObject>

#include "globals.h"

namespace ART {
namespace Models {
  class RendererModel;
} // nameSpace Models

namespace Logic {
} // nameSpace Logic

namespace Controllers {

class ADVANCED_RAY_TRACER_EXPORT RendererController  : public QQuickFramebufferObject
{
    Q_OBJECT

public:
    RendererController();

    QQuickFramebufferObject::Renderer *createRenderer() const;

private:
    // qreal m_t;
    // Models::RendererModel *m_renderer;
};

} // namespace Controllers
} // namespace ART
