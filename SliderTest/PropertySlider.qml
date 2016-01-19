import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
Item {
    id: rootItem
    property string name
    property real minimumValue
    property real maximumValue
    property real value: mySlider.value
    property Slider slider: mySlider
    height: row.height
    width: row.width

    Row {
        id: row
        Label {
            text: name+': '
        }
        Slider {
            id: mySlider
            minimumValue: rootItem.minimumValue
            maximumValue: rootItem.maximumValue
            value: rootItem.value
        }
    }
}
