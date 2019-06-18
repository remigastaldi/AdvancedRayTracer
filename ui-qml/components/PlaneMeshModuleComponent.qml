import AdvancedRayTracer 1.0
import "../styles"

import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

GroupBox {
  title: qsTr("PlaneMesh")

  ColumnLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true

    RowLayout {
      CustomText {
        color: Style.likeWhite
        text: "Width: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: PlaneMeshModel.width

        onEditingFinished: {
          PlaneMeshModel.setWidth(parseFloat(text))
        }
      }
    }
    RowLayout {
      CustomText {
        color: Style.likeWhite
        text: "Height: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: PlaneMeshModel.height

        onEditingFinished: {
          PlaneMeshModel.setHeight(parseFloat(text))
        }
      }
    }
  }
}