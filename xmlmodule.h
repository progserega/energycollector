#ifndef XMLMODULE_H
#define XMLMODULE_H

#include <QObject>
#include <QXmlStreamReader>
#include <QFile>

class xmlModule : public QObject
{
    Q_OBJECT
public:
    QXmlStreamReader *xml;
    QFile* file;

    explicit xmlModule(QString filename);
    ~xmlModule(void);


signals:

public slots:

private:
};

#endif // XMLMODULE_H
