import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

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
            zIndexModuleComponent.instance.destroy()
          if (transform2DModuleComponent.instance != null)
            transform2DModuleComponent.instance.destroy()
          for (var module in arr) {
            console.log("activate ==> " + arr[module]);
            switch (arr[module]) {
              // 2D
              case "ZIndex":
                zIndexModuleComponent.createObject("ZIndexModuleComponent.qml");
                break;
              case "Transform2D":
                transform2DModuleComponent.createObject("Transform2DModuleComponent.qml");
                break;
              // 3D
              case "Transform3D":
                transform3DModuleComponent.createObject("Transform3DModuleComponent.qml");
                break;
            }
          }
        }
      }
      ColumnLayout {
        Layout.fillWidth: true
        Layout.fillHeight: true
        // spacing: 20

        Item {
          width:250
          height: 45
          id: zIndexModuleComponent
          property var instance : null
          function createObject(qml) {
            instance = Qt.createComponent(qml).createObject(zIndexModuleComponent);
          }
        }
        Item {
          width:250
          height: 200
          id: transform2DModuleComponent
          property var instance : null
          function createObject(qml) {
            instance = Qt.createComponent(qml).createObject(transform2DModuleComponent);
          }
        }
        Item {
          width:250
          height: 200
          id: transform3DModuleComponent
          property var instance : null
          function createObject(qml) {
            instance = Qt.createComponent(qml).createObject(transform3DModuleComponent);
          }
        }
      }
    }
  }
}