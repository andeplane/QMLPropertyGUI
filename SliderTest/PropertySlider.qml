import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
Row {
    id: rootItem
    property string name
    property Slider slider: mySlider
    property real labelWidth: 80
    spacing: 5
    width: 200

    Label {
        text: name+': '
    }
    Slider {
        id: mySlider
        width: rootItem.width - labelWidth - rootItem.spacing
        minimumValue: rootItem.minimumValue
        maximumValue: rootItem.maximumValue
        value: rootItem.value
    }
}
