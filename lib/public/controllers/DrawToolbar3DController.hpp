#pragma once

#include "globals.h"

#include <QObject>
#include <QString>

namespace ART {
namespace Models {
} // namespace Models

namespace Controllers {

class ADVANCED_RAY_TRACER_EXPORT DrawToolbar3DController : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(DrawToolbar3DController)

public:
  explicit DrawToolbar3DController(QObject* parent = nullptr);
  ~DrawToolbar3DController() override = default;

  // void setModel(ART::Models::DrawToolbar3DModel* model);

private:
  // ART::Models::DrawToolbar3DModel *_model{nullptr};

// public Q_SLOTS:
  // void createSphere() noexcept;

Q_SIGNALS:
  void createSphere();
  void createCube();
  void createTorus();
  void castRay();
  void raytracingReflection();
  void import3DModel(const QUrl &);
  void import3DScene(const QUrl &);

  void createLight();

  // void createSphereEvent() noexcept;
};

} // namespace Controllers
} // namespace ART
