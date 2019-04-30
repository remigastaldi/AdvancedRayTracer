import "../styles"
import AdvancedRayTracer 1.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.3

GroupBox {
  title: qsTr("Light Picker")
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
            model: LightPickerModel.lights
            currentIndex: LightPickerModel.lightSelected
            width: 200
            onActivated: {
              LightPickerModel.pickLight(currentText);
              mainController.updateUiModules();
            }
        }
      }
    }
  }
}
