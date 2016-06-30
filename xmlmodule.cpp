#include "xmlmodule.h"
#include "listview.h"
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QGuiApplication>

xmlModule::xmlModule(QObject *parent) : QObject(parent)
{
    qDebug() << __FUNCTION__ << ":" << __LINE__;
}

//void xmlModule::setList(listView *data)
void xmlModule::setEngine(QQmlApplicationEngine *data)
{
    engine=data;
}
void xmlModule::setList(QStringList *data)
{
    list=data;
}

void xmlModule::cppMethod(QString text)
{
    list->append("test c++ append" + text);
    qDebug() << "C++ method called!" << text;
    engine->rootContext()->setContextProperty("listModelCitySearchId", QVariant::fromValue(*list));
}
