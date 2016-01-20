#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QQuickItem>
#include <QVariantList>
#include <QVariantMap>
#include <QVariant>

class Property : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(float min READ min WRITE setMin NOTIFY minChanged)
    Q_PROPERTY(float max READ max WRITE setMax NOTIFY maxChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
public:
    float m_value = 0;
    float m_min = 0;
    float m_max = 0;
    QString m_name;

    Property(QString name, float min, float max, float value);
    Property() { }
    float value() const;
    float min() const;
    float max() const;
    QString name() const;

public slots:
    void setValue(float value);
    void setMin(float min);
    void setMax(float max);
    void setName(QString name);

signals:
    void valueChanged(float value);
    void minChanged(float min);
    void maxChanged(float max);
    void nameChanged(QString name);
    void buttonPressed();
};

class Properties : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QVariantList properties READ properties WRITE setProperties NOTIFY propertiesChanged)
private:
    QVariantList m_properties;

public:
    explicit Properties(QQuickItem *parent = 0);
    ~Properties();
    void createProperty(QString name, float min, float max, float value);
    QVariantList properties() const;

signals:
    void propertiesChanged(QVariantList properties);

public slots:
    void setProperties(QVariantList properties);
};

#endif // PROPERTIES_H
