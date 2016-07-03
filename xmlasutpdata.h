#ifndef XMLASUTPDATA_H
#define XMLASUTPDATA_H

#include <QObject>
#include <QStringList>
#include "xmlmodule.h"


class xmlAsutpData : public xmlModule
{
    Q_OBJECT
public:
    //QStringList* getNasPunkts(void);
    QStringList* getNasPunkts(QStringList*result, QString search_text);
    xmlAsutpData(QString filename) : xmlModule(filename) {}
};

#endif // XMLASUTPDATA_H
