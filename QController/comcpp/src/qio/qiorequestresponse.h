#ifndef QSERIALREQUESTRESPONSE_H
#define QSERIALREQUESTRESPONSE_H

#include <QObject>
#include <QQueue>

#include "qtlog/qloggableobject.h"
#include "qserialsettings.h"
#include "qioabstract.h"
#include "qiotransactionbase.h"

class QIORequestResponse : public QtLog::QLoggableObject
{
    Q_OBJECT

public:
    QIORequestResponse(QIODevice * const device = nullptr,
                           QObject* parent = nullptr,
                           const QString prefix = "");
    ~QIORequestResponse();

    void addTransaction(QIOTransactionPtr transaction);

signals:
    void rMsg(const QVector<uint8_t> payload);

public slots:

public:
    // Getters
    QIOAbstract * device() const { return mDevice; }

protected slots:
    virtual void onByte(uint8_t byte) = 0;
    virtual void onMsg(const QVector<uint8_t> payload) = 0;

protected:

private slots:
    void mOnRx(QVector<uint8_t> data);
    void mOnTransFinished();
    void mStartTrans(QIOTransactionPtr trans);

private:
    QIOAbstract * const mDevice;
    QQueue<QIOTransactionPtr> mTransQueue;
    QIOTransactionPtr mPendingTrans;
};

#endif // QSERIALREQUESTRESPONSE_H
