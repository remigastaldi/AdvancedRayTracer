import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

GroupBox {
  title: qsTr("CuboidMesh")

  ColumnLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true

    RowLayout {
      CustomText {
        color: Style.likeWhite
        text: "xExtent: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: CuboidMeshModel.xExtent

        onEditingFinished: {
          CuboidMeshModel.setXExtent(parseFloat(text))
        }
      }
    }
    RowLayout {
      CustomText {
        color: Style.likeWhite
        text: "yExtent: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: CuboidMeshModel.yExtent

        onEditingFinished: {
          CuboidMeshModel.setYExtent(parseFloat(text))
        }
      }
    }
    RowLayout {
      CustomText {
        color: Style.likeWhite
        text: "zExtent: "
        Layout.leftMargin: 5
      }
      CustomDoubleInput {
        text: CuboidMeshModel.zExtent

        onEditingFinished: {
          CuboidMeshModel.setZExtent(parseFloat(text))
        }
      }
    }
  }        
}
