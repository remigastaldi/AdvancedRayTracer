import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

GroupBox {
  title: qsTr("TorusMesh")

  ColumnLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true

      // spacing: 4
    RowLayout {
      CustomText {
        color: Style.likeWhite
        text: "Minor Radius: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: TorusMeshModel.minorRadius

        onEditingFinished: {
          TorusMeshModel.setMinorRadius(parseFloat(text))
        }
      }
    }
    RowLayout {
      CustomText {
        color: Style.likeWhite
        text: "Radius: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: TorusMeshModel.radius

        onEditingFinished: {
          TorusMeshModel.setRadius(parseFloat(text))
        }
      }
    }
    RowLayout {    
      CustomText {
        color: Style.likeWhite
        text: "Rings: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: TorusMeshModel.rings

        onEditingFinished: {
          TorusMeshModel.setRings(parseInt(text))
        }
      }
    }

    RowLayout {
      CustomText {
        color: Style.likeWhite
        text: "Slices: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: TorusMeshModel.slices

        onEditingFinished: {
          TorusMeshModel.setSlices(parseInt(text))
        }
      }
    }
  }        
}
