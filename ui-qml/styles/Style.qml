pragma Singleton
import QtQuick 2.0

QtObject {
  id: style

  //General used by many properties
  property color mainColor: "orange"

  property color mainContainerColor: "#1B1E2B"
  // property color containerColor: "#292D3E"
  // property color containerBorderColor: "#D3DAE3"
  property int mainBorderWidth: 1
  property int mainBorderRadius: 5
  // property int containerBorderWidth: 1
  // property int containerBorderRadius: 5

  // Toolbar properties
  property int toolbarIconSize: 14
  property color toolbarIconColor: "#497EBE"
}
