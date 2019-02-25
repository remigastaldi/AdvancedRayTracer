#include "MainController.hpp"
#include "ToolbarController.hpp"
#include "RightSidebarController.hpp"
#include "DrawToolbar3DController.hpp"
#include "DrawToolbar2DController.hpp"

#include "ToolbarModel.hpp"
#include "RightSidebarModel.hpp"
#include "Scene3D.hpp"
#include "Scene2D.hpp"

#include <QApplication>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
  QApplication::setApplicationName("AdvancedRayTracer");
  QCoreApplication::setOrganizationName("Team 5");
  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QApplication app(argc, argv);
  
  QStringList fonts = QStringList{} << ":/fonts/Hack-Regular.ttf" << ":/fonts/Hack-Bold.ttf"
                                    << ":/fonts/Hack-BoldItalic.ttf" << ":/fonts/Hack-Italic.ttf"
                                    << ":/fonts/fontello.ttf";

  for (const auto& font : fonts) {
    if (QFontDatabase::addApplicationFont(font) == -1) {
        qWarning() << "Failed to load font: " << font;
    }
  }

  qmlRegisterType<ART::Controllers::MainController>("AdvancedRayTracer", 1, 0, "MainController");
  qmlRegisterType<ART::Controllers::ToolbarController>("AdvancedRayTracer", 1, 0, "ToolbarController");
  qmlRegisterType<ART::Controllers::RightSidebarController>("AdvancedRayTracer", 1, 0, "RightSidebarController");
  qmlRegisterType<ART::Controllers::DrawToolbar3DController>("DrawToolbar3DController", 1, 0, "DrawToolbar3DController");
  qmlRegisterType<ART::Controllers::DrawToolbar2DController>("DrawToolbar2DController", 1, 0, "DrawToolbar2DController");
  qmlRegisterType<ART::Logic::Scene3D>("AdvancedRayTracer", 1, 0, "CustomScene3D");
  qmlRegisterType<ART::Logic::Scene2D>("AdvancedRayTracer", 1, 0, "CustomScene2D");

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

  auto toolBarModel = new ART::Models::ToolbarModel;
  mainController.toolbarController()->setModel(toolBarModel);

  auto rightSidebarModel = new ART::Models::RightSidebarModel;
  mainController.rightSidebarController()->setModel(rightSidebarModel);

  engine.rootContext()->setContextProperty("mainController", &mainController);
  engine.rootContext()->setContextProperty("menuModel", toolBarModel);
  engine.rootContext()->setContextProperty("rightSidebarModel", rightSidebarModel);
  engine.load(QUrl(QStringLiteral("qrc:/views/MainView.qml")));

  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  auto *scene3D =  engine.rootObjects().first()->findChild<ART::Logic::Scene3D*>("customScene3D");
  mainController.setScene3D(scene3D);

  auto *scene2D =  engine.rootObjects().first()->findChild<ART::Logic::Scene2D*>("customScene2D");
  mainController.setScene2D(scene2D);

  mainController.dumpObjectTree();
  return QApplication::exec();
}
