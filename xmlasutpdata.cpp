#include "xmlasutpdata.h"
#include <QStringList>
#include <QDebug>
#include <QXmlQuery>
#include <QXmlFormatter>

QStringList* xmlAsutpData::getNasPunkts(QStringList*result, QString search_text)
{
    qDebug() << __FUNCTION__ << ":" << __LINE__;

    QString q="doc($inputDocument)/root/item[contains(child::nas_punkt, \"" + search_text + "\")]/<p>{string(nas_punkt)}</p>";

    //QString q="doc($inputDocument)/root/item/<p>{string(nas_punkt)}</p>";
    //QString q="doc($inputDocument)/root/item[xs:integer(@dom) = 18]/<p>{string(potrebitel)}</p>";
    //QString q="doc($inputDocument)/cookbook/recipe[@xml:id = \"MushroomSoup\"]/ingredient[@unit = \"milliliters\"]/<p>{@name, @quantity, @unit}</p>";
   // QString q="doc($inputDocument)/cookbook/recipe/<p>{string(title)}</p>";
    //QString q="doc($inputDocument)/cookbook/recipe [child::title = \"Quick and Easy Mushroom Soup\"]/<p>{string(title)}</p>";
  //  QString q="(: Select all recipes. :) declare variable $inputDocument external; doc($inputDocument)/cookbook/recipe/<p>{string(title)}</p>";
  //  QString q="doc($inputDocument)/cookbook/recipe/<p>{string(title)}</p>";

    query->setQuery(q);
    if (!query->isValid())
    {
        qDebug() << __FUNCTION__ << ":" << __LINE__ << "Query '" << q << "' is invalid! See https://www.w3.org/TR/xquery/";
        return NULL;
    }

    QXmlFormatter formatter(*query, buffer);
    if (!query->evaluateTo(&formatter))
    {
        qDebug() << __FUNCTION__ << ":" << __LINE__ << "No data finded";
        return NULL;
    }

    qDebug() << __FUNCTION__ << ":" << __LINE__ << QString::fromUtf8(outArray->constData());
    *result=QString::fromUtf8(outArray->constData()).split("\n");
    result->removeDuplicates();
    return result;
}
