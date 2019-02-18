#pragma once

#include <memory>

#include <QtQuick/QQuickFramebufferObject>
#include <QtQuick/qquickitem.h>

#include "RenderObject.hpp"
#include "Transform3D.hpp"

#include "globals.h"
#include <iostream>
namespace ART {
namespace Models {
} // nameSpace Models

namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT FbItem : public QQuickFramebufferObject {
  Q_OBJECT
  Q_DISABLE_COPY(FbItem)

public:
enum class Type {
  CUBE
};

struct Data {
  Type type;
  Transform3D transform;
  // Todo: Add data like sahders, color etc
};

public:
  FbItem();
  ~FbItem() override = default;
  FbItem(FbItem &&other) = delete;
  FbItem &operator=(FbItem &&other) = delete;

  int autoRate() const noexcept;

  const std::unordered_map<size_t, Data> &shapes() const noexcept;
protected:
  QQuickFramebufferObject::Renderer *createRenderer() const noexcept override;

private:
  int _renderFps;

  std::unordered_map<size_t, Data> _shapes;
  size_t _currentId;

public Q_SLOTS:
  void setAutoRenderRate(int fps) noexcept;
  
  void createCube() noexcept;
  void deleteShape() noexcept;
};

} // nameSpace Logic
} // namespace ART