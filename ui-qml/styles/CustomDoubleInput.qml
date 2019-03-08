import "../styles"
import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

TextInput {
  color: Style.likeWhite
  Layout.preferredWidth: 30
  wrapMode: TextInput.Wrap
  validator: DoubleValidator { bottom:0; top: 20000}

  onActiveFocusChanged: {
  if (activeFocus) {
      selectAll()
    }
  }
}
