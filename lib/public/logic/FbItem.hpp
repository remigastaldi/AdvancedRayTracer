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


  void setAutoRenderFps(int fps) noexcept;
  const std::unordered_map<size_t, Data> &shapes() const noexcept;
  void createCube() noexcept;

protected:
  QQuickFramebufferObject::Renderer *createRenderer() const noexcept override;

private:
  int _renderFps;

  std::unordered_map<size_t, Data> _shapes;
  size_t _currentId;

public Q_SLOTS:
  void test();
};

} // nameSpace Logic
} // namespace ART