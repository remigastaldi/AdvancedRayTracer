import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import Qt.labs.platform 1.1
import QtGraphicalEffects 1.12
import "../styles"

ToolBar {
    RowLayout {
        id: menuRow
        anchors.fill: parent

        ToolbarButton {
            Layout.leftMargin: 10
            id: newButton
            text: "\uE800" // icon-doc-text-inv-1
            focusPolicy: Qt.TabFocus
            onClicked: mainController.toolbarController.newFileClicked();
        }

        ToolbarButton {
            id: saveButton
            text: "\uE802" // icon-doc-text-inv-1
            focusPolicy: Qt.TabFocus
            onClicked: saveDialog.open()
        }
    
        Text {
            id: menuTitle
            text: "Test File"
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            Layout.fillWidth: true
            color: Style.mainColor
        }
    }

    FileDialog {
        id: saveDialog
        fileMode: FileDialog.SaveFile
        nameFilters: ["*"]
        folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
        onAccepted: mainController.toolbarController.saveAsFileClicked(file);
    }

    Shortcut {
        id: saveAsShortcut
        sequence: StandardKey.SaveAs
        onActivated: saveDialog.open()
    }

    Shortcut {
        id: saveShortcut
        sequence: StandardKey.Save
        onActivated: menuModel.isNewFile ? saveDialog.open() : mainController.toolbarController.saveFileClicked();
    }

    Shortcut {
        id: newShortcut
        sequence: StandardKey.New
        onActivated: mainController.toolbarController.newFileClicked();
    }

    Shortcut {
        id: exitShortcut
        sequence: StandardKey.Quit
        onActivated: Qt.quit();
    }
}
