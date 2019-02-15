#pragma once

#include <QObject>
#include <QString>

#include "globals.h"

namespace ART {
namespace Logic {
  class FbItem;
} // namespace Logic

namespace Controllers {

class ToolbarController;
class RightSidebarController;
class LeftSidebarController;

class ADVANCED_RAY_TRACER_EXPORT MainController : public QObject {
  Q_OBJECT
  Q_DISABLE_COPY(MainController)

  Q_PROPERTY(ART::Controllers::ToolbarController* toolbarController READ toolbarController CONSTANT)
  Q_PROPERTY(ART::Controllers::RightSidebarController* rightSidebarController READ rightSidebarController CONSTANT)
  Q_PROPERTY(ART::Controllers::LeftSidebarController* leftSidebarController READ leftSidebarController CONSTANT)
  Q_PROPERTY(ART::Logic::FbItem* fbItem READ fbItem CONSTANT)

public:
  explicit MainController(QObject* parent = nullptr);
  ~MainController() = default;
  MainController(MainController&& other) = delete;
  MainController& operator=(MainController&& other) = delete;

  void  setFbItem(Logic::FbItem *FbItem) noexcept;

public Q_SLOTS:
  ToolbarController* toolbarController() const noexcept;
  RightSidebarController *rightSidebarController() const noexcept;
  LeftSidebarController *leftSidebarController() const noexcept;
  Logic::FbItem *fbItem() const noexcept;

private:
  ToolbarController* _toolbarController{nullptr};
  RightSidebarController* _rightSidebarController{nullptr};
  LeftSidebarController* _leftSidebarController{nullptr};
  Logic::FbItem *_fbItem{nullptr};

private Q_SLOTS:
  void handleSaveFileClicked();
  void handleSaveAsFileClicked(const QUrl& url);
  void handleNewFileClicked();
};

} // namespace Controllers
} // namespace ART
