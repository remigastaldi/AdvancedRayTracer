import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import "../styles"

ColumnLayout {
  id: root

// anchors.fill: parent
// Layout.fillWidth: true
// Layout.fillHeight: true

  // Layout.minimumWidth: rectangle.Layout.minimumWidth
  // Layout.preferredWidth: rectangle.Layout.preferredWidth
  // Layout.maximumWidth: rectangle.Layout.maximumWidth

  // Layout.minimumHeight: rectangle.Layout.minimumHeight
  // Layout.preferredHeight: rectangle.Layout.preferredHeight
  // Layout.maximumHeight: rectangle.Layout.maximumHeight

  Rectangle {
    id: rectangle

    color: "steelblue"

    Layout.fillWidth: true
    Layout.fillHeight: true

    Layout.minimumWidth: 200
    Layout.preferredWidth: 200
    Layout.maximumWidth: 250

    Layout.minimumHeight: 150
    Layout.preferredHeight: 700
    Layout.maximumHeight: 1000
  }
}
