#ifndef XMLMODULE_H
#define XMLMODULE_H

#include <QObject>
#include <QXmlStreamReader>
#include <QFile>

class xmlModule : public QObject
{
    Q_OBJECT
public:
    explicit xmlModule(QString filename);
    ~xmlModule(void);


signals:

public slots:

private:
        QXmlStreamReader *xml;
        QFile* file;
};

#endif // XMLMODULE_H
