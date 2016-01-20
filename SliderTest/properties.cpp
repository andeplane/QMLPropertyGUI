#include "properties.h"
#include <QDebug>

Properties::Properties(QQuickItem *parent) : QQuickItem(parent)
{
    createProperty("value1", 0, 10, 5);
    createProperty("value2", 0, 5, 2.5);
}

Properties::~Properties()
{
    for(QVariant &variant : m_properties) {
        Property *property = variant.value<Property*>();
        delete property;
    }
    m_properties.clear();
}

void Properties::createProperty(QString name, float min, float max, float value)
{
    Property *property = new Property(name, min, max, value);
    m_properties.append(QVariant::fromValue(property));
}

QVariantList Properties::properties() const
{
    return m_properties;
}

void Properties::setProperties(QVariantList properties)
{
    if (m_properties == properties)
        return;

    m_properties = properties;
    emit propertiesChanged(properties);
}

Property::Property(QString name, float min, float max, float value)
{
    m_name = name;
    m_min = min;
    m_max = max;
    m_value = value;
}

float Property::value() const
{
    return m_value;
}

float Property::min() const
{
    return m_min;
}

float Property::max() const
{
    return m_max;
}

QString Property::name() const
{
    return m_name;
}

void Property::setValue(float value)
{
    if (m_value == value)
        return;

    m_value = value;
    emit valueChanged(value);
}

void Property::setMin(float min)
{
    if (m_min == min)
        return;

    m_min = min;
    emit minChanged(min);
}

void Property::setMax(float max)
{
    if (m_max == max)
        return;

    m_max = max;
    emit maxChanged(max);
}

void Property::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(name);
}
