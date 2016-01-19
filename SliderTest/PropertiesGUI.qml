import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import Properties 1.0

Rectangle {
    id: propertiesGUIRoot
    property variant properties
    property real labelWidth: 80
    Column {
        anchors.fill: parent
        id: column
        spacing: 5
    }

    onPropertiesChanged: {
        rebuild()
    }

    function rebuild() {
        if(properties === undefined) {
            return
        }

        for(var i = column.children.length; i > 0 ; i--) {
            column.children[i-1].destroy()
        }

        for(i in properties) {
            var thisProperty = properties[i]
            var name = thisProperty.name
            var type = thisProperty.type
            var guiType = thisProperty.guiType
            var min = thisProperty.min
            var max = thisProperty.max
            if(type.toLowerCase() === "float" || type.toLowerCase() === "double") {
                if(guiType.toLowerCase() === "slider") {
                    addSlider(name, min, max)
                } else if(guiType.toLowerCase() === "textfield") {
                    addTextField(name, true)
                }
            } else if(type.toLowerCase() === "string") {
                if(guiType.toLowerCase() === "textfield") {
                    addTextField(name, false)
                }
            }
        }
    }

    function addRow(name) {
        var rowObject = Qt.createQmlObject('import QtQuick 2.5; Row { spacing: 5; }',
                                           column,
                                           "");
        var labelObject = Qt.createQmlObject('import QtQuick.Controls 1.4; Label {width: '+propertiesGUIRoot.labelWidth+'; text: \''+name+': \'}',
                                             rowObject,
                                             "")
        return rowObject
    }

    function addTextField(name, numbersOnly) {
        var rowObject = addRow(name)
        if(numbersOnly) {
            var textfieldObject = Qt.createQmlObject('import QtQuick.Controls 1.4; TextField { inputMethodHints: Qt.ImhFormattedNumbersOnly; text: propertiesGUIRoot.parent[\''+name+'\'].toFixed(3); onTextChanged: { propertiesGUIRoot.parent[\''+name+'\'] = parseFloat(text) } }',
                                           rowObject,
                                           "");
        } else {
            textfieldObject = Qt.createQmlObject('import QtQuick.Controls 1.4; TextField { inputMethodHints: Qt.ImhFormattedNumbersOnly; text: propertiesGUIRoot.parent[\''+name+'\']; onTextChanged: { propertiesGUIRoot.parent[\''+name+'\'] = text } }',
                                           rowObject,
                                           "");
        }

    }

    function addSlider(name, min, max) {
        var componentWidth = propertiesGUIRoot.width - propertiesGUIRoot.labelWidth
        var rowObject = addRow(name)

        var sliderObject = Qt.createQmlObject('import QtQuick.Controls 1.4; Slider { width: '+componentWidth+'; minimumValue: '+min+'; maximumValue: '+max+'; value: propertiesGUIRoot.parent[\''+name+'\']; onValueChanged: { propertiesGUIRoot.parent[\''+name+'\'] = value; } }',
                                           rowObject,
                                           "");
    }
}
