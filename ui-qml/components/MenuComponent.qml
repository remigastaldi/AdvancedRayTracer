import QtQuick 2.11
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.4
import Qt.labs.platform 1.0
import QtGraphicalEffects 1.0
import "../styles"

ToolBar {
    RowLayout {
        id: menuRow

        MenuToolButton {
            Layout.leftMargin: 10
            id: newButton
            text: "\uE800" // icon-doc-text-inv-1
            focusPolicy: Qt.TabFocus
            onClicked: mainController.menuController.newFileClicked();
        }

        MenuToolButton {
            id: saveButton
            text: "\uE802" // icon-floppy
            focusPolicy: Qt.TabFocus
            onClicked: saveDialog.open()
        }
    }

    FileDialog {
        id: saveDialog
        fileMode: FileDialog.SaveFile
        nameFilters: ["*"]
        folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
        onAccepted: mainController.menuController.saveAsFileClicked(file);
    }

    Shortcut {
        id: saveAsShortcut
        sequence: StandardKey.SaveAs
        onActivated: saveDialog.open()
    }

    Shortcut {
        id: saveShortcut
        sequence: StandardKey.Save
        onActivated: menuModel.isNewFile ? saveDialog.open() : mainController.menuController.saveFileClicked();
    }

    Shortcut {
        id: newShortcut
        sequence: StandardKey.New
        onActivated: mainController.menuController.newFileClicked();
    }
}
