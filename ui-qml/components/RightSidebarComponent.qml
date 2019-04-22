import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3

UiMainBorder {
  id: root

  ColumnLayout {
    id: column
    anchors.top: root.top
    anchors.right: root.right
    anchors.left: root.left

    GroupBox {      
      id: outLiner
      font.pointSize: 10
      title: qsTr("Outliner")
      Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
      Layout.fillWidth: true
      Layout.rightMargin: 5
      Layout.leftMargin: 5
      Layout.preferredHeight: 200

      Outliner {
        anchors.fill: parent
      }
    }
  
    GroupBox {
      title: qsTr("Components")
      font.pointSize: 10
      id: componentsBox
      Layout.fillWidth: true
      Layout.rightMargin: 5
      Layout.leftMargin: 5
      Layout.maximumHeight: root.height - outLiner.height - 10

      Component.onCompleted: {
        mainController.updateUiModules.connect(updateModules);
        function updateModules() {
          mainController.initEntityModulesModels()
          var modules = mainController.loadTree()

          moduleComponent.clear()
          for (var module in modules) {
            moduleComponent.append({moduleSource: modules[module] + "ModuleComponent.qml"})
          }
        }
      }

      ScrollView {
        clip: true
        anchors.fill: parent

        ListView {
          Layout.fillWidth: true
          Layout.fillHeight: true
          Layout.alignment: Qt.AlignHCenter
          
          model: moduleComponent
          delegate: Component {
            id: delegateComponent
            Loader {
              source: moduleSource
            }
          }
        }
        ListModel {
          id: moduleComponent
          ListElement { moduleSource: "" }
        }
      }
    }
  }
}