#ifndef XMLMODULE_H
#define XMLMODULE_H

#include <QObject>

class xmlModule : public QObject
{
    Q_OBJECT
public:
    explicit xmlModule(QObject *parent = 0);

signals:

public slots:
};

#endif // XMLMODULE_H
