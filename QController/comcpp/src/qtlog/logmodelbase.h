#ifndef LOGMODELBASE_H
#define LOGMODELBASE_H

#include <QAbstractListModel>

#include "log.h"
#include "../types.h"

namespace QtLog {
    class LogModelBase : public QAbstractListModel
    {
        Q_OBJECT

    public:
        // Constructor
        explicit LogModelBase(QObject *parent = nullptr);

        // Roles definition
        enum {
            dateTime = Qt::UserRole,
            threadNumber,
            type,
            category,
            msg,
            file,
            callFunction,
            lineNumber
        };

        // Basic  QAbstractListModel functionality
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        Qt::ItemFlags flags(const QModelIndex &index) const override;
        virtual QHash<int, QByteArray> roleNames() const override;
        Q_INVOKABLE int roleIndexForStringName(QByteArray name);

    public slots:

    signals:

    protected:
        QList<LogMessage> mList;
        // Helpers
        virtual LogMessage readRow(int index) const;

    };
} // QtLog

#endif // LOGMODELBASE_H
