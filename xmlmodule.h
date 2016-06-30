#ifndef XMLMODULE_H
#define XMLMODULE_H

//#include <QDeclarativeItem>
#include <QObject>
#include "listview.h"
#include <QQmlApplicationEngine>

class xmlModule : public QObject
{
    Q_OBJECT
public:
    explicit xmlModule(QObject *parent = 0);
    void setList(QStringList *data);
    void setEngine(QQmlApplicationEngine *data);
    //listView *list;
    QQmlApplicationEngine *engine;
    QStringList *list;

signals:

public slots:
   void cppMethod(QString text);
};

#endif // XMLMODULE_H
