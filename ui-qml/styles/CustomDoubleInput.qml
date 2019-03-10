import "../styles"
import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

TextInput {
  UiMainBorder {
    width : (textInput.length * 8) + 14
    height: 20
    anchors.horizontalCenter: parent.horizontalCenter
    z: -1
  }
  id: textInput
  color: Style.likeWhite
  wrapMode: TextInput.Wrap
  validator: DoubleValidator { bottom:-200000; top: 200000}
 
  onActiveFocusChanged: {
  if (activeFocus) {
      selectAll()
    }
  }
}
