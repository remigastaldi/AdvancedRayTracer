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

  GroupBox {
    id: outLiner
    title: qsTr("Outliner")
    anchors.top: root.top
    anchors.right: root.right
    anchors.left: root.left
    anchors.margins: 10
    height: 200
    Outliner {
      anchors.fill: parent
    }
  }
 
  ColumnLayout {
    id: column
    anchors.top: outLiner.bottom
    anchors.right: root.right
    anchors.left: root.left
    anchors.topMargin: 10
  
    GroupBox {
      Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
      Layout.fillWidth: true
      Layout.rightMargin: 10
      Layout.leftMargin: 10
      // Layout.fillHeight: true
      Component.onCompleted: {
        mainController.selectedShapeUpdate.connect(selectedShapeUpdate);
        function selectedShapeUpdate()  {
          zIndexModuleComponent.visible = false;
          var arr = mainController.loadTree()
          for (var module in arr) {
            if (arr[module] == "zIndex") {
              mainController.test()
              zIndexModuleComponent.visible = true;
              // console.log("activate" + arr[module]);
              // console.log("==> " mainController);
            }
          }
        }
      }
      ZIndexModuleComponent {
        Layout.fillWidth: true
        visible : false;
        id: zIndexModuleComponent
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