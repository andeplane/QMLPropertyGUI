#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "properties.h"
#include <QtQml>

int main(int argc, char *argv[])
{
    qmlRegisterType<Properties>("Properties", 1, 0, "Properties");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
