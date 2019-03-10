#pragma once

#include "globals.h"

#include <QObject>
#include <QString>

namespace ART {
namespace Models {
} // namespace Models

namespace Controllers {

class ADVANCED_RAY_TRACER_EXPORT DrawToolbar2DController : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(DrawToolbar2DController)
  // Q_PROPERTY(bool isDrawing READ isDrawing NOTIFY isDrawingChanged);

public:
  explicit DrawToolbar2DController(QObject* parent = nullptr);
  ~DrawToolbar2DController() = default;

  // void setModel(ART::Models::DrawToolbar2DModel* model);

  // bool isDrawing();

Q_SIGNALS:
  void createLine();
  void createRectangle();
  void createCircle();
  void createTriangle();
  void createPolygon();
  void cutImage();
  void importImg(const QUrl& file_url);
  void saveScene(const QUrl& file_url);

  void isDrawingChanged(bool isDrawing);

private:
  // ART::Models::DrawToolbar2DModel *_model{nullptr};
};

} // namespace Controllers
} // namespace ART
