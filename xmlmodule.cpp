#include "xmlmodule.h"
#include "listview.h"
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QGuiApplication>
#include <QXmlStreamReader>
#include <QXmlQuery>
#include <QXmlFormatter>
#include <QBuffer>
#include <QByteArray>

xmlModule::xmlModule(QString filename)
{
    qDebug() << __FUNCTION__ << ":" << __LINE__;
    file = new QFile(filename);
    if (!file->open(QIODevice::ReadOnly))
    {
        qDebug() << __FUNCTION__ << ":" << __LINE__ << "Error open XML-file: " << filename;
        file=NULL;
        return;
    }
}

int xmlModule::xmlQuery(QString xmlQuery, QStringList *result)
{
    QByteArray outArray;
    QBuffer buffer(&outArray);
    buffer.open(QIODevice::ReadWrite);

    QXmlQuery query;
    file->seek(0);
    query.bindVariable("inputDocument", file);

    query.setQuery(xmlQuery);
    if (!query.isValid())
    {
        qDebug() << __FUNCTION__ << ":" << __LINE__ << "Query '" << xmlQuery << "' is invalid! See https://www.w3.org/TR/xquery/";
        return false;
    }

    QXmlFormatter formatter(query, &buffer);
    if (!query.evaluateTo(&formatter))
    {
        qDebug() << __FUNCTION__ << ":" << __LINE__ << "No data finded";
        return false;
    }

    //qDebug() << __FUNCTION__ << ":" << __LINE__ << QString::fromUtf8(outArray->constData());
    result->clear();
    *result=QString::fromUtf8(outArray.constData()).split("\n");
    result->removeDuplicates();

    qDebug() << __FUNCTION__ << ":" << __LINE__ << "Found " << result->size() << "unicum values";
    qDebug() << __FUNCTION__ << ":" << __LINE__ << "Last value = '" << result[result->size()-1] << "'";
    buffer.close();
    return true;

}


xmlModule::~xmlModule()
{
    if(file!=NULL)delete file;
}
