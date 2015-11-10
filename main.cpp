#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include "clicker.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Clicker>("clicker", 1, 0, "Clicker");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

