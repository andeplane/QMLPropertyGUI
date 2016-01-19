#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QQuickItem>
#include <QVariantList>
#include <QVariantMap>

class Property : public QObject
{

};

class Properties : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double value1 READ value1 WRITE setValue1 NOTIFY value1Changed)
    Q_PROPERTY(double value2 READ value2 WRITE setValue2 NOTIFY value2Changed)
    Q_PROPERTY(double penisSize READ penisSize WRITE setPenisSize NOTIFY penisSizeChanged)
    Q_PROPERTY(QVariantList properties READ properties WRITE setProperties NOTIFY propertiesChanged)
private:
    double m_value1 = 6;
    double m_value2 = 0;
    double m_penisSize = 0;
    QVariantList m_properties;

public:
    explicit Properties(QObject *parent = 0);
    double value1() const
    {
        return m_value1;
    }

    double value2() const
    {
        return m_value2;
    }

    double penisSize() const
    {
        return m_penisSize;
    }

    QVariantList properties() const
    {
        return m_properties;
    }

signals:

    void value1Changed(double value1);
    void value2Changed(double value2);
    void penisSizeChanged(double penisSize);
    void propertiesChanged(QVariantList properties);

public slots:
    void setValue1(double value1)
    {
        if (m_value1 == value1)
            return;

        m_value1 = value1;
        qDebug() << "Value 1:" << m_value1;
        emit value1Changed(value1);
    }
    void setValue2(double value2)
    {
        if (m_value2 == value2)
            return;

        m_value2 = value2;
        qDebug() << "Value 2:" << m_value2;
        emit value2Changed(value2);
    }
    void setPenisSize(double penisSize)
    {
        if (m_penisSize == penisSize)
            return;

        m_penisSize = penisSize;
        qDebug() << "penisSize:" << m_penisSize;
        emit penisSizeChanged(penisSize);
    }
    void setProperties(QVariantList properties)
    {
        if (m_properties == properties)
            return;

        m_properties = properties;
        emit propertiesChanged(properties);
    }
};

#endif // PROPERTIES_H
