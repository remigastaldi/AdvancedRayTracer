pragma Singleton
import QtQuick 2.0

QtObject {
    id: style

    //General used by many properties
    property color mainBlueColor: "#497EBE"

    // //Menu properties
    property int menuIconSize: 14
    property alias menuIconColor: style.mainBlueColor
}
