import "../styles"
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import AdvancedRayTracer 1.0
import QtQuick.Dialogs 1.0

UiMainBorder {
  GroupBox {
    title: qsTr("Shapes")
    anchors.right: parent.right
    anchors.left: parent.left
    anchors.top: parent.top
    anchors.margins: 10

    ColumnLayout {
      id: column
      anchors.fill: parent
      spacing: 10

      Button {
        Layout.alignment: Qt.AlignHCenter
        text: "Rectangle"
        onClicked: mainController.drawToolbar2DController.createRectangle()
      }

      Button {
        Layout.alignment: Qt.AlignHCenter
        text: "Import image"
		onClicked: importImgDialog.open()
      }
	FileDialog {
		id: importImgDialog
		title: "Please choose an image"
		folder: shortcuts.home
		nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
		onAccepted: {
			mainController.drawToolbar2DController.importImg(importImgDialog.fileUrl)
	    }
  }
	}
  }
}