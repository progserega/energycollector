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
