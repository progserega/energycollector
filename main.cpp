#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "qml2ctranslator.h"
#include "listview.h"
#include "xmlasutpdata.h"
#include <QQmlContext>


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    // Загрузка XML с данными:
    xmlAsutpData asutpData(QString("in.xml"));

    qml2Ctranslator qml2c;
    qml2c.setEngine(&engine);
    qml2c.setAsutpData(&asutpData);

    engine.rootContext()->setContextProperty("qml2c", &qml2c);


    return app.exec();
}
