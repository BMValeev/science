#include "qiorequestresponse.h"

#include <QTime>

#include "../utils.h"

QIORequestResponse::QIORequestResponse(QIODevice * const device,
                                       QObject *parent,
                                       const QString prefix)
    : QLoggableObject(parent, prefix == ""? "QSerialRequestResponse --> " : prefix)
    , mDevice(new QIOAbstract(device, this))
    , mPendingTrans(nullptr)
{
    connect(mDevice, &QIOAbstract::response, this, &QIORequestResponse::mOnRx);
    connect(this, &QIORequestResponse::rMsg, this, [=](const QVector<uint8_t> payload) {
        this->onMsg(payload);
        if (mPendingTrans) mPendingTrans->onMsg(payload);
    });
}

QIORequestResponse::~QIORequestResponse() { }

void QIORequestResponse::addTransaction(QIOTransactionPtr transaction)
{
    if (!transaction)
        return;

    Q_ASSERT(transaction);

    if (mTransQueue.isEmpty()) {
        mStartTrans(transaction);
    } else {
        mTransQueue.enqueue(transaction);
    }
}

void QIORequestResponse::mOnRx(QVector<uint8_t> data)
{
    for (auto& byte: data)
        onByte(byte);
}

void QIORequestResponse::mOnTransFinished()
{
    if (!mTransQueue.isEmpty()) {
        mStartTrans(mTransQueue.dequeue());
    } else {
        mPendingTrans = nullptr;
    }
}

void QIORequestResponse::mStartTrans(QIOTransactionPtr trans)
{
    if (mPendingTrans) {
        mPendingTrans->disconnect();
    }

    mPendingTrans = trans;

    connect(mPendingTrans.data(), &QIOTransactionBase::completed, this, &QIORequestResponse::mOnTransFinished);

    mDevice->mSend(mPendingTrans->txData());
    mPendingTrans->setPending();
}
