import QtQuick 2.11
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.4
import "../styles"

Item {
  ColumnLayout {
    id: root

    anchors.fill: parent
    Rectangle {
      color: "steelblue"
    width: 300
    height: 300
    anchors.fill: parent
      // Layout.alignment: Qt.AlignLeft | Qt.AlignRight | Qt.AlignTop | Qt.AlignBottom
    }
  }
}