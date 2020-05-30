#include "logmodelbase.h"

QtLog::LogModelBase::LogModelBase(QObject *parent)
    : QAbstractListModel(parent)
{

}

int QtLog::LogModelBase::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return mList.size();
}

QVariant QtLog::LogModelBase::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int i = index.row();
    LogMessage message = readRow(i);

    switch (role) {
    case dateTime:
        return QVariant::fromValue(message.dateTime.toString(Log::dateFormat));
    case threadNumber:
        return QVariant::fromValue(message.threadNumber);
    case type:
        return QVariant::fromValue(message.type);
    case category:
        return QVariant::fromValue(message.category);
    case msg:
        return QVariant::fromValue(message.msg);
    case file:
        return QVariant::fromValue(message.file);
    case callFunction:
        return QVariant::fromValue(message.function);
    case lineNumber:
        return QVariant::fromValue(message.lineNumber);
    }
    return QVariant();
}

Qt::ItemFlags QtLog::LogModelBase::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::NoItemFlags;
}

QHash<int, QByteArray> QtLog::LogModelBase::roleNames() const
{
    QHash<int, QByteArray> names;
    // Only one role name - the text of the row itself
    names[dateTime] = "datetime";
    names[threadNumber] = "threadNumber";
    names[type] = "type";
    names[category] = "category";
    names[msg] = "message";
    names[file] = "file";
    names[callFunction] = "callFunction";
    names[lineNumber] = "lineNumber";

    return names;
}

int QtLog::LogModelBase::roleIndexForStringName(QByteArray name)
{
    return roleNames().key(name);
}

QtLog::LogMessage QtLog::LogModelBase::readRow(int index) const
{
    return mList.at(index);
}

