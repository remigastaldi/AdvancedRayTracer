#pragma once

#include "PaintedItem.hpp"
#include "Scene.hpp"
#include "Shape2D.hpp"
#include "globals.h"

#include <unordered_map>

namespace ART {
namespace Logic {

class ADVANCED_RAY_TRACER_EXPORT Scene2D : public Scene {
  Q_OBJECT
  Q_DISABLE_COPY(Scene2D)

public:

  int _id = 0;
  double decalx = 0;
  double decaly = 0;
  int lastMouseX = 0;
  int lastMouseY = 0;
  bool userIsDrawing = false;
  bool cutImg = false;

  explicit Scene2D(PaintedItem *painter);

public Q_SLOTS:
  void createLine() noexcept;
  void createRectangle() noexcept;
  void createCircle() noexcept;
  void createTriangle() noexcept;
  void createPolygon() noexcept;
  void cutImage() noexcept;
  void importImg(const QUrl &url) noexcept;
  void saveScene(const QUrl &url) noexcept;

  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  void keyPressedEvent(Qt::Key event);

  const std::unordered_map<std::string, std::unique_ptr<Entity>> &entities() const noexcept override;
  Entity *selectedEntity() const noexcept override;
  void selectEntity(const std::string & id) noexcept override;
  void deleteSelectedEntity() noexcept;

  virtual void paint(QPainter *painter);

  void zIndexUpdate(size_t zIndex, const std::string &id);
  void zIndexDelete(size_t zIndex, const std::string &id);

  void update() noexcept override;

private:
  std::map<size_t, std::unordered_map<std::string, std::reference_wrapper<std::unique_ptr<Shape2D>>>> _zIndex;
  std::unordered_map<std::string, std::unique_ptr<Shape2D>> _entities;
  PaintedItem *_painter;
  Shape2D *_selectedShape;
};

} // namespace Logic
} // namespace ART