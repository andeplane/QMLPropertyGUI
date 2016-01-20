import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import Properties 1.0

Window {
    visible: true
    width: 1500
    height: 1000
    Properties {
        id: myProperties
        PropertiesGUI {
            width: 500
            properties: myProperties
        }
    }


}
