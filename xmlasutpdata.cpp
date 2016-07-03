#include "xmlasutpdata.h"
#include <QStringList>
#include <QDebug>

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
    xmlQuery(q, result);
    return result;

}
