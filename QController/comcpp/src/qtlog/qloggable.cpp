#include "qloggable.h"

void QtLog::QLoggable::msg(QtMsgType type, QLoggingCategory *cat, QString msg) const
{
    _msg(type, cat, msg);
}

void QtLog::QLoggable::_msg(QtMsgType type, QLoggingCategory *cat, QString msg) const
{
    QString s = mPrefix + msg;
    switch (type)
    {
        case QtInfoMsg:     qInfo(*cat) << s; break;
        case QtDebugMsg:    qDebug(*cat) << s; break;
        case QtWarningMsg:  qWarning(*cat) << s; break;
        case QtCriticalMsg: qCritical(*cat) << s; break;
        case QtFatalMsg:    qFatal("%s", s.toStdString().data());
    }
}

void QtLog::QLoggable::inf(QString msg, QLoggingCategory *cat) const
{
    this->msg(QtInfoMsg, cat, msg);
}

void QtLog::QLoggable::dbg(QString msg, QLoggingCategory *cat) const
{
    this->msg(QtDebugMsg, cat, msg);
}

void QtLog::QLoggable::wrn(QString msg, QLoggingCategory *cat) const
{
    this->msg(QtWarningMsg, cat, msg);
}

void QtLog::QLoggable::crit(QString msg, QLoggingCategory *cat) const
{
    this->msg(QtCriticalMsg, cat, msg);
}

void QtLog::QLoggable::fat(QString msg, QLoggingCategory *cat) const
{
    this->msg(QtFatalMsg, cat, msg);
}
