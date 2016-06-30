#ifndef LISTVIEW_H
#define LISTVIEW_H
//#include <QDeclarativeItem>
#include <QAbstractListModel>
#include <QStringList>

class listView : public QAbstractListModel
{
Q_OBJECT

public:
listView(QObject *parent = 0);

enum AnimalRoles {NameRole = Qt::UserRole + 1};

void addItem(const QString &text);
int rowCount(const QModelIndex & parent = QModelIndex()) const;
QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

public slots:
void append(const QString &text);

private:
QStringList itemList;
};

#endif // LISTVIEW_H
