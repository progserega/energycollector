#include "qml2ctranslator.h"
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QGuiApplication>


qml2Ctranslator::qml2Ctranslator(QObject *parent) : QObject(parent)
{
    // listGorod:
    listGorod = new QStringList;
}

void qml2Ctranslator::setEngine(QQmlApplicationEngine *data)
{
    engine=data;
}

void qml2Ctranslator::searchGorod(QString text)
{
    qDebug() << "C++ method called!" << text;
    //listGorod->append("test c++ append" + text);
    listGorod->append(text);
    engine->rootContext()->setContextProperty("listModelCitySearchId", QVariant::fromValue(*listGorod));
}
