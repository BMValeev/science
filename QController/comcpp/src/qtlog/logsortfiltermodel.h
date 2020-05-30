#ifndef LOGSORTFILTERMODEL_H
#define LOGSORTFILTERMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

#include "logmodelbase.h"
namespace QtLog {
    class LogSortFilterProxyModel : public QSortFilterProxyModel
    {
        Q_OBJECT
        Q_PROPERTY(LogModelBase* source READ source WRITE setSource NOTIFY sourceChanged)

    public:
        LogSortFilterProxyModel(QObject *parent = nullptr);

        LogModelBase* source() const;

    public slots:
        void setSource(LogModelBase* source);

    signals:
        void sourceChanged(LogModelBase* model);

    private:
        LogModelBase* mSource;
    };
} // QtLog
#endif // LOGSORTFILTERMODEL_H
