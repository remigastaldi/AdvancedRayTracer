import "../styles"
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import AdvancedRayTracer 1.0
import QtQuick.Dialogs 1.3
import Qt.labs.platform 1.1
import QtGraphicalEffects 1.12

UiMainBorder {
  GroupBox {
    id: tools
    title: qsTr("2D Tools")
    font.pointSize: 10
    anchors.right: parent.right
    anchors.left: parent.left
    anchors.top: parent.top
    anchors.margins: 10
    property variant drawing: null

    Component.onCompleted: {
      mainController.drawToolbar2DController.isDrawingChanged.connect(isDrawingChanged);
      function isDrawingChanged(val) {
        if (val == false)
          tools.drawing.textColor = Style.likeWhite
      }
    }

    ColumnLayout {
      id: column
      anchors.fill: parent
      spacing: 10

      CustomButton {
        Layout.alignment: Qt.AlignHCenter
        text: "Import image"
    		onClicked: importImgDialog.open()
      }

      CustomButton {
          Layout.alignment: Qt.AlignHCenter
          text: "Line"
          onClicked: {
            mainController.drawToolbar2DController.createLine()
            this.textColor =  Style.mainColor
            tools.drawing = this
          }
        }

      CustomButton {
          Layout.alignment: Qt.AlignHCenter
          text: "Square"
          highlighted: false
          onClicked: {
            mainController.drawToolbar2DController.createRectangle()
            this.textColor =  Style.mainColor
            tools.drawing = this
          }
        }

      CustomButton {
          Layout.alignment: Qt.AlignHCenter
          text: "Ellipse"
          onClicked: {
            mainController.drawToolbar2DController.createCircle()
            this.textColor =  Style.mainColor
            tools.drawing = this
          }
        }

      CustomButton {
          Layout.alignment: Qt.AlignHCenter
          text: "Triangle"
          onClicked: {
            mainController.drawToolbar2DController.createTriangle()
            this.textColor =  Style.mainColor
            tools.drawing = this
          }
        }

      CustomButton {
          Layout.alignment: Qt.AlignHCenter
          text: "Polygon"
          onClicked: {
            mainController.drawToolbar2DController.createPolygon()
            this.textColor =  Style.mainColor
            tools.drawing = this
          }
        }

		CustomButton {
          Layout.alignment: Qt.AlignHCenter
          text: "Copy image"
          onClicked: {
            mainController.drawToolbar2DController.cutImage()
            this.textColor =  Style.mainColor
            tools.drawing = this
          }
        }

      CustomButton {
          Layout.alignment: Qt.AlignHCenter
          text: "Save scene"
          onClicked: saveSceneDialog.open()
        }

      FileDialog {
        id: importImgDialog
        title: "Please choose an image"
        folder: shortcuts.home
        nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
        onAccepted: {
          mainController.drawToolbar2DController.importImg(file)
        }
      }

      FileDialog {
          id: saveSceneDialog
      fileMode: FileDialog.SaveFile
      title: "Please choose a location"
          nameFilters: ["*"]
          folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
          onAccepted: mainController.drawToolbar2DController.saveScene(file);
      }
  	}
  }
}