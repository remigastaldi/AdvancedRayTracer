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
      Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
      Layout.fillWidth: true
      Layout.rightMargin: 10
      Layout.leftMargin: 10
      // Layout.fillHeight: true
      Component.onCompleted: {
        mainController.selectedShapeUpdate.connect(selectedShapeUpdate);
        function selectedShapeUpdate() {
          mainController.initEntityModulesModels()
          var arr = mainController.loadTree()

          if (zIndexModuleComponent.instance != null)
            zIndexModuleComponent.instance.destroy()
          if (transform2DModuleComponent.instance != null)
            transform2DModuleComponent.instance.destroy()
          for (var module in arr) {
            console.log("activate ==> " + arr[module]);
            switch (arr[module]) {
              case "ZIndex":
                zIndexModuleComponent.createObject("ZIndexModuleComponent.qml");
                break;
              case "Transform2D":
                transform2DModuleComponent.createObject("Transform2DModuleComponent.qml");
                break;
            }
          }
        }
      }
      ColumnLayout {
      // Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        Layout.fillWidth: true
        Layout.fillHeight: true
        spacing: 20

        Item {
          // Layout.fillWidth: true
          // Layout.fillHeight: true
          width:250
          height: 30
          id: zIndexModuleComponent
          property var instance : null
          function createObject(qml) {
            instance = Qt.createComponent(qml).createObject(zIndexModuleComponent);
          }
        }
        Item {
          width:250
          height: 200
          // Layout.fillHeight: true
          // Layout.fillWidth: true
          id: transform2DModuleComponent
          property var instance : null
          function createObject(qml) {
            instance = Qt.createComponent(qml).createObject(transform2DModuleComponent);
          }
        }
      }
    }

    // Button {
    //   Layout.alignment: Qt.AlignHCenter
    //   text: "Add cube"
    //   onClicked: mainController.rightSidebarController.createCube();
    // }

    // Button {
    //   Layout.alignment: Qt.AlignHCenter
    //   text: "Delete cube"
    //   onClicked: mainController.rightSidebarController .deleteShape()
    // }

    // RowLayout {
    //   Layout.bottomMargin: 10
    //   Layout.leftMargin: 10
    //   spacing: 10

    //   Text {
    //     text: "Render per second"
    //   }
    //   TextInput {
    //     Layout.preferredWidth: 70
    //     Layout.alignment: Qt.AlignHCenter
    //     text: "0"
    //     renderType: TextInput.NativeRendering
    //     validator: IntValidator{bottom: 0; top: 2000000;}
    //     onTextEdited: mainController.rightSidebarController.setAutoRenderRate(parseInt(text))
    //   }
    // }
  }
}