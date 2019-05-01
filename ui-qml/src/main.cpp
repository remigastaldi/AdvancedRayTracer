#include "CameraController.hpp"
#include "DrawToolbar2DController.hpp"
#include "DrawToolbar3DController.hpp"
#include "MainController.hpp"
#include "RightSidebarController.hpp"
#include "ToolbarController.hpp"

#include "PaintedItem.hpp"
#include "RenderItem.hpp"
#include "RightSidebarModel.hpp"
#include "RootEntity.hpp"
#include "Scene2D.hpp"
#include "Scene3D.hpp"
#include "ToolbarModel.hpp"

#include "QmlOutliner.hpp"

#include <QApplication>
#include <QDebug>
#include <QFontDatabase>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
  QApplication::setApplicationName("AdvancedRayTracer");
  QCoreApplication::setOrganizationName("Team 5");
  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QApplication app(argc, argv);

  QStringList fonts = QStringList{} << ":/fonts/Hack-Regular.ttf"
                                    << ":/fonts/Hack-Bold.ttf"
                                    << ":/fonts/Hack-BoldItalic.ttf"
                                    << ":/fonts/Hack-Italic.ttf"
                                    << ":/fonts/fontello.ttf";

  for (const auto &font : fonts) {
    if (QFontDatabase::addApplicationFont(font) == -1) {
      qWarning() << "Failed to load font: " << font;
    }
  }

  qmlRegisterType<ART::Controllers::MainController>("AdvancedRayTracer", 1, 0, "MainController");
  qmlRegisterType<ART::Controllers::ToolbarController>("AdvancedRayTracer", 1, 0, "ToolbarController");
  qmlRegisterType<ART::Controllers::RightSidebarController>("AdvancedRayTracer", 1, 0, "RightSidebarController");
  qmlRegisterType<ART::Controllers::DrawToolbar3DController>("AdvancedRayTracer", 1, 0, "DrawToolbar3DController");
  qmlRegisterType<ART::Controllers::DrawToolbar2DController>("AdvancedRayTracer", 1, 0, "DrawToolbar2DController");
  qmlRegisterType<ART::Logic::RootEntity>("AdvancedRayTracer", 1, 0, "RootEntity");
  qmlRegisterType<ART::Logic::PaintedItem>("AdvancedRayTracer", 1, 0, "CustomPaintedItem");
  qmlRegisterType<ART::Logic::RenderItem>("AdvancedRayTracer", 1, 0, "CustomRenderItem");
  qmlRegisterType<ART::Logic::Scene3D>("AdvancedRayTracer", 1, 0, "Scene3D");
  qmlRegisterType<ART::Controllers::CameraController>("AdvancedRayTracer", 1, 0, "CameraController");
  // qmlRegisterType<ART::Logic::RenderItem>("AdvancedRayTracer", 1, 0, "RenderController");

  QSurfaceFormat format;
  if (QOpenGLContext::openGLModuleType() == QOpenGLContext::LibGL) {
    format.setVersion(3, 3);
    format.setProfile(QSurfaceFormat::CoreProfile);
  }
  format.setDepthBufferSize(24);
  format.setStencilBufferSize(8);
  format.setSamples(4);
  QSurfaceFormat::setDefaultFormat(format);

  QQmlApplicationEngine engine;

  ART::Controllers::MainController mainController;
  mainController.setEngine(&engine);
  engine.rootContext()->setContextProperty("mainController", &mainController);

  ART::Models::ToolbarModel toolbarModel;
  mainController.toolbarController()->setModel(&toolbarModel);
  engine.rootContext()->setContextProperty("menuModel", &toolbarModel);

  ART::Models::RightSidebarModel rightSidebarModel;
  mainController.rightSidebarController()->setModel(&rightSidebarModel);
  engine.rootContext()->setContextProperty("rightSidebarModel", &rightSidebarModel);

  ART::UI::QmlOutliner qmlOutliner;
  mainController.setOutliner(&qmlOutliner);
  engine.rootContext()->setContextProperty("qmlOutliner", &qmlOutliner);

  engine.load(QUrl(QStringLiteral("qrc:/views/MainView.qml")));

  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  auto *rootEntity = engine.rootObjects().first()->findChild<ART::Logic::RootEntity *>("rootEntity");
  ART::Logic::Scene3D scene3D(rootEntity);
  mainController.setScene3D(&scene3D);

  auto *paintedItem = engine.rootObjects().first()->findChild<ART::Logic::PaintedItem *>("paintedItem");
  ART::Logic::Scene2D scene2D(paintedItem);
  mainController.setScene2D(&scene2D);

  mainController.dumpObjectTree();
  return QApplication::exec();
}
