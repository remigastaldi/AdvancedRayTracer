import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3

UiMainBorder {
  id: root

  // Layout.fillWidth: true
  // Layout.fillHeight: true

  // Layout.minimumWidth: 250
  // Layout.preferredWidth: 250
  // Layout.maximumWidth: 300

  // Layout.maximumHeight: column.implicitHeight

  ColumnLayout {
    id: column
    anchors.top: outLiner.bottom
    anchors.right: root.right
    anchors.left: root.left
    anchors.topMargin: 10
 
    GroupBox {      
      id: outLiner
      title: qsTr("Outliner")

      Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
      Layout.fillWidth: true
      Layout.rightMargin: 10
      Layout.leftMargin: 10
      Layout.preferredHeight: 200

      Outliner {
        anchors.fill: parent
      }
    }
  
    GroupBox {
      title: qsTr("Components")
      Layout.alignment: Qt.AlignHCenter | Qt.AlignTop | Qt.AlignBottom
      Layout.fillWidth: true
      Layout.rightMargin: 10
      Layout.leftMargin: 10
      // Layout.fillHeight: true
      Component.onCompleted: {
        mainController.updateUiModules.connect(updateModules);
        function updateModules() {
          mainController.initEntityModulesModels()
          var arr = mainController.loadTree()

          if (zIndexModuleComponent.instance != null)
            zIndexModuleComponent.visble = false
          if (transform2DModuleComponent.instance != null)
            transform2DModuleComponent.visble = false
          for (var module in arr) {
            console.log("activate ==> " + arr[module]);
            switch (arr[module]) {
              // 2D
              case "ZIndex":
                zIndexModuleComponent.visible = true
                break;
              case "Transform2D":
                transform2DModuleComponent.visible = true
                break;
              // 3D
              case "Transform3D":
                transform3DModuleComponent.visible = true
                break;
              case "Brush":
                brushModuleComponent.visible = true
                break;
              case "Pen":
                penModuleComponent.visible = true
                break;
            }
          }
        }
      }
      ColumnLayout {
        Layout.fillWidth: true
        Layout.fillHeight: true
        spacing: 5

        ZIndexModuleComponent {
          Layout.fillWidth: true
          Layout.fillHeight: true
          Layout.maximumWidth: 200
          // height: 45
          id: zIndexModuleComponent
          visible: false
        }
        Transform2DModuleComponent {
          Layout.fillWidth: true
          Layout.fillHeight: true
          Layout.maximumWidth: 200
          // height: 45
          id: transform2DModuleComponent
          visible: false
        }
        Transform3DModuleComponent {
          Layout.fillWidth: true
          Layout.fillHeight: true
          Layout.maximumWidth: 200
          // height: 45
          id: transform3DModuleComponent
            visible: false
        }
        BrushModuleComponent {
          // height: 45
          Layout.fillWidth: true
          Layout.fillHeight: true
          Layout.maximumWidth: 200
          id: brushModuleComponent
          visible: false
        }
        PenModuleComponent {
          // height: 45
          Layout.fillWidth: true
          Layout.fillHeight: true
          Layout.maximumWidth: 200
          id: penModuleComponent
          visible: false
        }
      }
    }
  }
}