import QtQuick 2.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0
import "."

ToolButton {
    id: root
    implicitWidth: contentItem.implicitWidth * 1.5

    contentItem: Text {
        text: root.text
        font.family: "fontello"
        font.pointSize: Style.toolbarIconSize
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: Style.toolbarIconColor
    }
}