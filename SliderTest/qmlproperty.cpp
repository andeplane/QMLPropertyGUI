#include "qmlproperty.h"
#include <QVariantMap>
QVariantMap createProperty(QString name, QString type, QString guiType, float min, float max) {
    QVariantMap property;
    property["name"] = name;
    property["type"] = type;
    property["guiType"] = guiType;
    property["min"] = min;
    property["max"] = max;
    return property;
}
