#ifndef XMLASUTPDATA_H
#define XMLASUTPDATA_H
#include <QStringList>
#include "xmlmodule.h"


class xmlAsutpData : public xmlModule
{
public:
    QStringList* getNasPunkts(void);
    QStringList* getNasPunkts2(void);
    xmlAsutpData(QString filename) : xmlModule(filename) {}
};

#endif // XMLASUTPDATA_H
