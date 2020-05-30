#ifndef QLOGGABLE_H
#define QLOGGABLE_H

#include <QString>
#include <QLoggingCategory>

namespace QtLog {

class QLoggable
{
public:
    QLoggable(QString prefix = "")
        : mPrefix(prefix)
    { }

    virtual ~QLoggable() { }

private:
    const QString mPrefix;

protected:
    const QString logPrefix() const { return mPrefix; }

    virtual void msg(QtMsgType type, QLoggingCategory* cat, QString msg) const;
    void _msg(QtMsgType type, QLoggingCategory* cat, QString msg) const;
    // Log functions will also emit message signal
    void inf(QString msg, QLoggingCategory* cat = QLoggingCategory::defaultCategory()) const;
    void dbg(QString msg, QLoggingCategory* cat = QLoggingCategory::defaultCategory()) const;
    void wrn(QString msg, QLoggingCategory* cat = QLoggingCategory::defaultCategory()) const;
    void crit(QString msg, QLoggingCategory* cat = QLoggingCategory::defaultCategory()) const;
    void fat(QString msg, QLoggingCategory* cat = QLoggingCategory::defaultCategory()) const;
};

} // QtLog

#endif // QLOGGABLE_H
