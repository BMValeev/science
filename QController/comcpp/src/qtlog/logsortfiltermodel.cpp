#include "logsortfiltermodel.h"

QtLog::LogSortFilterProxyModel::LogSortFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
    , mSource(nullptr)
{
    connect(this,&LogSortFilterProxyModel::sourceChanged,
            this,[=](LogModelBase* source) {
        if (source != nullptr) {
            setSourceModel(source);
        }
    });

}

QtLog::LogModelBase *QtLog::LogSortFilterProxyModel::source() const
{
    return mSource;
}

void QtLog::LogSortFilterProxyModel::setSource(LogModelBase *source)
{
    if (mSource == source)
        return;

    mSource = source;
    emit sourceChanged(mSource);
}
