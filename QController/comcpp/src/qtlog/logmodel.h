#ifndef LOGMODEL_H
#define LOGMODEL_H

#include <QAbstractListModel>
#include <QTimer>

#include "log.h"
#include "logmodelbase.h"
#include "logfilemodel.h"
#include "../types.h"

#define MAX_DISPLAYED 2000
#define BUFFER_WATCH_INTERVAL_MS 100
namespace QtLog {
    class LogModel : public LogModelBase
    {
        Q_OBJECT

    public:
        // Constructor
        explicit LogModel(QObject *parent = nullptr);

    public slots:
        void removeFirstMessages(int count);
        void addMessages(QList<LogMessage> messages);
        void flushModel();
        void bufferWatch();

    signals:

    private:
        QList<LogMessage> mBuffer;
        QTimerPtr mBufferWatcher;

    };
} // QtLog
#endif // LOGMODEL_H
