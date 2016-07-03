#ifndef XMLMODULE_H
#define XMLMODULE_H

#include <QObject>
#include <QXmlStreamReader>
#include <QFile>
#include <QBuffer>
#include <QByteArray>
#include <QXmlQuery>
#include <QXmlFormatter>

class xmlModule : public QObject
{
    Q_OBJECT
public:
    QXmlStreamReader *xml;
    QFile* file;
    QByteArray *outArray;
    QBuffer *buffer;
    QXmlQuery *query;

    explicit xmlModule(QString filename);
    ~xmlModule(void);


signals:

public slots:

private:
};

#endif // XMLMODULE_H
