#include "qiotransactionbase.h"

#include <QEventLoop>
#include <QTimer>
#include <QThread>

#include "../utils.h"

QIOTransactionBase::QIOTransactionBase(const QVector<uint8_t>& txData,
                                       int timeout,
                                       const QString prefix,
                                       QObject *parent)
    : QLoggableObject(parent, prefix == ""? "QIOTransactionBase --> " : prefix)
    , mTxData(txData)
    , mStatus(STATUS::NOTSENT)
    , mExpirationWatcher(this)
    , mElapsedTimer()
{
    qRegisterMetaType<STATUS>("STATUS");

    connect(this, &QIOTransactionBase::statusChanged, this, &QIOTransactionBase::mOnStatusChanged);
    connect(&mExpirationWatcher, &QTimer::timeout, this, &QIOTransactionBase::mOnExpirationTimeout);

    // Setup expiration watcher
    mExpirationWatcher.setInterval(timeout);
    mExpirationWatcher.setSingleShot(true);

    // qInfo() << "QIOTransactionBase created, thread = " << QThread::currentThreadId() << ", address = " << this;
}

QIOTransactionBase::~QIOTransactionBase() {
    // qInfo() << "QIOTransactionBase destroyed, thread = " << QThread::currentThreadId() << ", address = " << this;
}

/*QIOTransactionBase::STATUS QIOTransactionBase::wait(int timeout)
{
    if (mStatus == STATUS::RESPONSED || mStatus == STATUS::EXPIRED)
        return mStatus;

    if (timeout <= 0)
        return mStatus;

    QEventLoop* loop = new QEventLoop(this);
    QTimer* timer = new QTimer(this);

    timer->setSingleShot(true);
    QObject::connect(timer, &QTimer::timeout, loop, &QEventLoop::quit);
    QObject::connect(this, &QIOTransactionBase::completed, loop, &QEventLoop::quit);

    timer->start(timeout);
    loop->exec();

    if (timer->isActive())
        timer->stop();

    return mStatus;
}*/

void QIOTransactionBase::onMsg(QVector<uint8_t> payload)
{
    // QByteArray pa(reinterpret_cast<const char*>(payload.data()), payload.size());
    // inf("onMsg = " + pa.toHex(':') + ", elapsed = " + QString::number(mElapsedTimer.elapsed()));

    if (mStatus != STATUS::PENDING)
        return;

    if (isResponsed(payload)) {
        mStatus = STATUS::RESPONSED;
        emit statusChanged(mStatus);
    }
}

void QIOTransactionBase::setPending()
{
    if (mStatus != STATUS::NOTSENT)
        return;

    mStatus = STATUS::PENDING;
    emit statusChanged(mStatus);
}

void QIOTransactionBase::mOnStatusChanged(QIOTransactionBase::STATUS status)
{
    Q_UNUSED(status)

    switch (mStatus) {
    case STATUS::PENDING:
        mExpirationWatcher.start();
        mElapsedTimer.start();
        emit sent();
        break;
    case STATUS::RESPONSED:
        emit responsed();
        emit completed(mStatus);
        break;
    case STATUS::EXPIRED:
        emit expired();
        emit completed(mStatus);
        break;
    default:
        return;
    }
}

void QIOTransactionBase::mOnExpirationTimeout()
{
    mStatus = STATUS::EXPIRED;
    inf("expired");
    emit statusChanged(mStatus);
}
