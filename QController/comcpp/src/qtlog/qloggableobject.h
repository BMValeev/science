#ifndef QLOGGABLEOBJECT_H
#define QLOGGABLEOBJECT_H

#include <QString>
#include <QObject>
#include <QLoggingCategory>

#include "qloggable.h"

namespace QtLog {

class QLoggableObject : public QObject, public QLoggable
{
    Q_OBJECT

public:
    QLoggableObject(QObject* parent = nullptr, QString prefix = "")
        : QObject(parent)
        , QLoggable(prefix)
    { }

signals:
    void message(QString _msg, QtMsgType type, QLoggingCategory* category) const;

protected:
    void msg(QtMsgType type, QLoggingCategory* cat, QString msg) const override;
};

} // QtLog

#endif // QLOGGABLEOBJECT_H
