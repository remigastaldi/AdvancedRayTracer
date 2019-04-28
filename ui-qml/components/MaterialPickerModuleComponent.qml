import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3

GroupBox {
  title: qsTr("Material Picker")
  ColumnLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true
    // spacing: 10

    ColumnLayout {
      Layout.fillWidth: true
      Layout.fillHeight: true

      RowLayout {
  
        ComboBox {
            id: cbItems
            model: MaterialPickerModel.materials
            width: 200
            onActivated: {
              MaterialPickerModel.pickMaterial(currentText);
              mainController.updateUiModules();
            }
        }
      }
    }
  }
}
