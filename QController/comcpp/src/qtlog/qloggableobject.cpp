#include "qloggableobject.h"

#include <QDebug>

void QtLog::QLoggableObject::msg(QtMsgType type, QLoggingCategory *cat, QString msg) const
{
    _msg(type, cat, msg);
    emit message(msg, type, cat);
}
