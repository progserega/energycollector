#include "xmlmodule.h"
#include "listview.h"
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QGuiApplication>
#include <QXmlStreamReader>

xmlModule::xmlModule(QString filename)
{
    xml = NULL;
    qDebug() << __FUNCTION__ << ":" << __LINE__;
    file = new QFile(filename);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << __FUNCTION__ << ":" << __LINE__ << "Error open XML-file: " << filename;
        file=NULL;
        return;
    }
    xml = new QXmlStreamReader(file);

}

xmlModule::~xmlModule()
{
    if(xml!=NULL)delete xml;
    if(file!=NULL)delete file;
}
