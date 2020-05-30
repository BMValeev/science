#ifndef LOGFILEMODEL_H
#define LOGFILEMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QFile>
#include <QDateTime>

#include "log.h"
#include "logmodelbase.h"
#include "../mqtextstream.h"

#define MAX_DISPLAYED 2000
namespace QtLog {
    class LogFileModel : public LogModelBase {
    Q_OBJECT
        Q_PROPERTY(QString source
                           READ
                           source
                           WRITE
                           setSource
                           NOTIFY
                           sourceChanged)

    public:
        // Constructor
        explicit LogFileModel(QObject *parent = nullptr);

        static LogMessage logMessageFromString(QString line);

        // Basic  QAbstractListModel functionality
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;

        // File to open
        QString source() const;

    public slots:

        void setSource(QString source);

        void flushModel();

    signals:

        void sourceChanged(QString source);

    private:
        int mRowCount = 0;
        QScopedPointer<QFile> mLogFile;

        int countRows();

    protected:
        LogMessage readRow(int index) const override;

    };
}// QtLog
#endif // LOGFILEMODEL_H
