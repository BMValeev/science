#ifndef QSERIALTRANSACTIONBASE_H
#define QSERIALTRANSACTIONBASE_H

#include <QVector>
#include <QSharedPointer>
#include <QTimer>
#include <QWaitCondition>
#include <QMutex>
#include <QElapsedTimer>

#include "qtlog/qloggableobject.h"

class QIOTransactionBase : public QtLog::QLoggableObject
{
    Q_OBJECT
    Q_PROPERTY(STATUS status READ status NOTIFY statusChanged)

public:    
    QIOTransactionBase(const QVector<uint8_t> &txData, int timeout, const QString prefix = "", QObject* parent = nullptr);
    virtual ~QIOTransactionBase();

    enum STATUS {
        NOTSENT = 0,
        PENDING = 1,
        RESPONSED = 2,
        EXPIRED = 3
    };

    // STATUS wait(int timeout);
    virtual bool isResponsed(QVector<uint8_t>& payload) = 0;

    // Getters
    const QVector<uint8_t>& txData() const { return mTxData; }
    bool isNotSent() const { return mStatus == STATUS::NOTSENT; }
    bool isPending() const { return mStatus == STATUS::PENDING; }
    bool isResponsed() const { return mStatus == STATUS::RESPONSED; }
    bool isExpired() const { return mStatus == STATUS::EXPIRED; }
    STATUS status() const { return mStatus; }

public slots:
    void onMsg(QVector<uint8_t> payload);
    void setPending();

signals:
    void statusChanged(STATUS status);
    void sent();
    void responsed();
    void expired();
    void completed(STATUS status);

private slots:
    void mOnStatusChanged(STATUS status);
    void mOnExpirationTimeout();

private:
    const QVector<uint8_t> mTxData;
    STATUS mStatus;
    QTimer mExpirationWatcher;
    QElapsedTimer mElapsedTimer;
};

typedef QSharedPointer<QIOTransactionBase> QIOTransactionPtr;

#endif // QSERIALTRANSACTIONBASE_H
