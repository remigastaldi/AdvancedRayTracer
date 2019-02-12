#pragma once

#include <QObject>
#include <QString>

#include "globals.h"

namespace ART {
namespace Models {
} // namespace Models

namespace Controllers {

class ToolbarController;
class RightSidebarController;
class LeftSidebarController;
class RendererController;

class ADVANCED_RAY_TRACER_EXPORT MainController : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MainController)

  Q_PROPERTY(ART::Controllers::ToolbarController* toolbarController READ toolbarController CONSTANT)
  Q_PROPERTY(ART::Controllers::RightSidebarController* rightSidebarController READ rightSidebarController CONSTANT)
  Q_PROPERTY(ART::Controllers::LeftSidebarController* leftSidebarController READ leftSidebarController CONSTANT)
  Q_PROPERTY(ART::Controllers::RendererController* rendererController READ rendererController CONSTANT)

public:
  explicit MainController(QObject* parent = nullptr);
  ~MainController() = default;
  MainController(MainController&& other) = delete;
  MainController& operator=(MainController&& other) = delete;

  void  setRendererController(RendererController *rendererController) noexcept;

public Q_SLOTS:
  ToolbarController* toolbarController() const noexcept;
  RightSidebarController *rightSidebarController() const noexcept;
  LeftSidebarController *leftSidebarController() const noexcept;
  RendererController *rendererController() const noexcept;

private:
  ToolbarController* _toolbarController{nullptr};
  RightSidebarController* _rightSidebarController{nullptr};
  LeftSidebarController* _leftSidebarController{nullptr};
  RendererController *_rendererController{nullptr};

private Q_SLOTS:
  void handleSaveFileClicked();
  void handleSaveAsFileClicked(const QUrl& url);
  void handleNewFileClicked();
};

} // namespace Controllers
} // namespace ART
