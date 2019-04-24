import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

GroupBox {
  title: qsTr("SphereMesh")

  ColumnLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true

    RowLayout {
      CustomText {
        color: Style.likeWhite
        text: "Generate Tangents: "
        Layout.leftMargin: 5
      }
      CheckBox {
        checked: SphereMeshModel.generateTangents

        nextCheckState: {
          SphereMeshModel.setGenerateTangents(checked)
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
        text: SphereMeshModel.radius

        onEditingFinished: {
          SphereMeshModel.setRadius(parseFloat(text))
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
        text: SphereMeshModel.rings

        onEditingFinished: {
          SphereMeshModel.setRings(parseInt(text))
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
        text: SphereMeshModel.slices

        onEditingFinished: {
          SphereMeshModel.setSlices(parseInt(text))
        }
      }
    }
  }        
}
