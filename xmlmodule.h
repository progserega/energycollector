#ifndef XMLMODULE_H
#define XMLMODULE_H

#include <QObject>
#include <QXmlStreamReader>
#include <QFile>
#include <QXmlQuery>
#include <QXmlFormatter>

class xmlModule : public QObject
{
    Q_OBJECT
public:
    QFile* file;

    int xmlQuery(QString xmlQuery, QStringList *result);
    explicit xmlModule(QString filename);
    ~xmlModule(void);


signals:

public slots:

private:
};

#endif // XMLMODULE_H
