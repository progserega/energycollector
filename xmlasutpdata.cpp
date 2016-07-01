#include "xmlasutpdata.h"
#include <QStringList>
#include <QDebug>
#include <QXmlQuery>
#include <QXmlFormatter>
#include <QBuffer>
#include <QByteArray>

QStringList* xmlAsutpData::getNasPunkts(void)
{
    QStringList *list = new QStringList;
  /*  if (xml==NULL)
    {
        qDebug() << __FUNCTION__ << ":" << __LINE__ << " Error xml-class not inicializised - xml==NULL";
        return NULL;
    }
    while (!xml.atEnd() && !xml.hasError())
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        if (token == QXmlStreamReader::StartDocument)
            continue;
        if (token == QXmlStreamReader::StartElement)
        {
            if (xml.name() == "item")
            {
            }
                continue;
            if (xml.name() == "etap")
                XMLConf.append(parseEtap(xml));
        }
    }*/
    return list;
}

QStringList* xmlAsutpData::getNasPunkts2(void)
{
    qDebug() << __FUNCTION__ << ":" << __LINE__;
    QStringList *list = new QStringList;
    //QString q="doc($inputDocument)/root/item[@nas_punkt = \"Партизанск\"]/<p>{string(potrebitel)}</p>";
    //QString q="doc($inputDocument)/root/item/<p>{string(nas_punkt)}</p>";
    //QString q="doc($inputDocument)/root/item[xs:integer(@dom) = 18]/<p>{string(potrebitel)}</p>";
 //   QString q="doc($inputDocument)/cookbook/recipe[@xml:id = \"MushroomSoup\"]/ingredient[@unit = \"milliliters\"]/<p>{@name, @quantity, @unit}</p>";
    QString q="doc($inputDocument)/cookbook/recipe/<p>{string(title)}</p>";
    QString q="(: Select all recipes. :) declare variable $inputDocument external; doc($inputDocument)/cookbook/recipe/<p>{string(title)}</p>";
  //  QString q="doc($inputDocument)/cookbook/recipe/<p>{string(title)}</p>";

    QFile sourceDocument;
    //sourceDocument.setFileName(":/files/cookbook.xml");
    sourceDocument.setFileName("in.xml");
    sourceDocument.open(QIODevice::ReadOnly);

    QByteArray outArray;
    QBuffer buffer(&outArray);
    buffer.open(QIODevice::ReadWrite);

    QXmlQuery query;
    query.bindVariable("inputDocument", &sourceDocument);
    query.setQuery(q);
    if (!query.isValid())
    {
        qDebug() << __FUNCTION__ << ":" << __LINE__ << "Query '" << q << "' is invalid! See https://www.w3.org/TR/xquery/";
        return NULL;
    }

    QXmlFormatter formatter(query, &buffer);
    if (!query.evaluateTo(&formatter))
    {
        qDebug() << __FUNCTION__ << ":" << __LINE__ << "No data finded";
        return NULL;
    }

    qDebug() << __FUNCTION__ << ":" << __LINE__ << QString::fromUtf8(outArray.constData());
    list->append(QString::fromUtf8(outArray.constData()));
    buffer.close();
    return list;
}
