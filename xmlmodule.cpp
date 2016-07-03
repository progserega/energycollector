#include "xmlmodule.h"
#include "listview.h"
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QGuiApplication>
#include <QXmlStreamReader>
#include <QXmlQuery>
#include <QXmlFormatter>

xmlModule::xmlModule(QString filename)
{
    qDebug() << __FUNCTION__ << ":" << __LINE__;
    xml = NULL;
    outArray = NULL;
    buffer = NULL;
    query = NULL;

    file = new QFile(filename);
    if (!file->open(QIODevice::ReadOnly))
    {
        qDebug() << __FUNCTION__ << ":" << __LINE__ << "Error open XML-file: " << filename;
        file=NULL;
        return;
    }
    outArray = new QByteArray ;
    buffer = new QBuffer(outArray);
    buffer->open(QIODevice::ReadWrite);

    query = new QXmlQuery;
    query->bindVariable("inputDocument", file);
}

xmlModule::~xmlModule()
{
    if(xml!=NULL)delete xml;
    if(file!=NULL)delete file;
    if(outArray!=NULL)delete outArray;
    if(query!=NULL)delete query;
    if(buffer!=NULL)
    {
        buffer->close();
        delete buffer;
    }
}
