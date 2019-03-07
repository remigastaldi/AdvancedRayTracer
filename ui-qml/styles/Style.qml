pragma Singleton
import QtQuick 2.0
// import QtQuick.Controls.Universal 2.1

QtObject {
  id: style

  //General used by many properties
  // property color mainColor: Universal.Orange
  property color mainColor: "orange"

  // property int mainContainerBackground: Universal.Steel
  property color mainContainerColor: "#1A1C20"
  // property color containerColor: "#292D3E"
  // property color mainContainerSecondaryColor: "#1B1E2B"
  // property color containerBorderColor: "#D3DAE3"
  property int mainBorderWidth: 1
  property int mainBorderRadius: 5
  // property int containerBorderWidth: 1
  // property int containerBorderRadius: 5

  // Toolbar properties
  property int toolbarIconSize: 16
  property color toolbarIconColor: "#497EBE"

  // property int boutonFontSize: 14
}
