#include "listview.h"

listView::listView(QObject *parent)
: QAbstractListModel(parent)
{
QHash<int, QByteArray> roles;
roles[NameRole] = "name";
//setRoleNames(roles);
}

void listView::append(const QString &text)
{
beginInsertRows(QModelIndex(), rowCount(), rowCount());
itemList.append(text);
endInsertRows();
}

int listView::rowCount(const QModelIndex & parent) const
{
return itemList.count();
}

QVariant listView::data(const QModelIndex & index, int role) const
{
if (index.row() < 0 || index.row() > itemList.count())
return QVariant();
return itemList.at(index.row());
}
