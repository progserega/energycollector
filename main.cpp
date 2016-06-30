#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "xmlmodule.h"
#include "listview.h"
#include <QQmlContext>

listView *listViewCitySearch;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    listViewCitySearch = new listView;
    xmlModule xml;
    QStringList dataList;
    //xml.setList(listViewCitySearch);
    xml.setEngine(&engine);
    xml.setList(&dataList);
    listViewCitySearch->append("test c++ append");


    //context->setContextProperty("cppObject", new xmlModule);
    engine.rootContext()->setContextProperty("cppObject", &xml);
    engine.rootContext()->setContextProperty("listModelCitySearchId", listViewCitySearch);

    listViewCitySearch->append("test c++ append");


    dataList.append("Item 1");
    dataList.append("Item 2");
    dataList.append("Item 3");
    dataList.append("Item 4");

    engine.rootContext()->setContextProperty("listModelCitySearchId", QVariant::fromValue(dataList));
//![0]
    dataList.clear();
    dataList.append("Item 6");
    dataList.append("Item 7");
    engine.rootContext()->setContextProperty("listModelCitySearchId", QVariant::fromValue(dataList));


    return app.exec();
}
