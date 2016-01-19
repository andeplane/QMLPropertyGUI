#include "properties.h"
#include "qmlproperty.h"
#include <QDebug>

Properties::Properties(QObject *parent) : QObject(parent)
{
    m_properties << createProperty("value1", "float", "Slider", 0, 10)
                << createProperty("value2", "float", "Slider", 2, 5)
                << createProperty("penisSize", "float", "Slider", 0, 30)
                << createProperty("penisSize", "float", "TextField", 0, 30);
}
