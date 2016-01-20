import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1


Rectangle {
    id: propertiesGUIRoot
    property variant properties
    property real labelWidth: 80
    color: "red"
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

        var propertyList = properties["properties"]
        for(var propertyIndex in propertyList) {
            var aProperty = propertyList[propertyIndex]
            addSlider(aProperty)
        }
    }

    function addSlider(aProperty) {
        var component = Qt.createComponent("PropertySlider.qml");
        if (component.status === Component.Ready) {
            var QMLObject = component.createObject(column, {});
            if(QMLObject===null) {
                console.log("Could not add slider...")
            } else {
                QMLObject.minimumValue = aProperty.min
                QMLObject.maximumValue = aProperty.max
                QMLObject.name = aProperty.name
                QMLObject.width = propertiesGUIRoot.width
                QMLObject.labelWidth = propertiesGUIRoot.labelWidth
                QMLObject.value = aProperty.value
                QMLObject.valueChanged.connect(function() {
                    aProperty.value = QMLObject.value
                })
                aProperty.valueChanged.connect(function() {
                    QMLObject.value = aProperty.value
                })
            }
        } else {
            console.log("Could not add slider...")
        }
    }
}
