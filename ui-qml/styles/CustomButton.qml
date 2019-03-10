import "../styles"
import QtQuick 2.12
import QtQuick.Controls 2.12

Button {
  id: root
  property alias textColor: text.color

  contentItem: Text {
    id: text
    text: root.text
    font.pointSize: Style.buttonFontSize
    color: Style.likeWhite
  }
}
