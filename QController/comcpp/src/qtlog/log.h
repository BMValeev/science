#ifndef LOG_H
#define LOG_H

#include <QObject>
#include <QAbstractListModel>
#include <QTextStream>
#include <QTextCodec>
#include <QDateTime>
#include <QScopedPointer>
#include <QFile>
#include <QFileInfo>
#include <QLoggingCategory>
#include <QThread>
#include <QDir>
#include <QRegularExpression>
#include <QProcess>
#include <QMutex>

#include "../utils.h"

// Additional categories
// Info
Q_DECLARE_LOGGING_CATEGORY(infoAppEvents)
Q_DECLARE_LOGGING_CATEGORY(infoUser)
Q_DECLARE_LOGGING_CATEGORY(debugHardware)
Q_DECLARE_LOGGING_CATEGORY(debugI2CHex)
Q_DECLARE_LOGGING_CATEGORY(debugSPIHex)
Q_DECLARE_LOGGING_CATEGORY(debugWarning)
Q_DECLARE_LOGGING_CATEGORY(python)

#define MAX_LOGSFOLDER_SIZE_MB 100
#define MAX_ARCHIVES_SIZE_MB 300

namespace QtLog {

class LogMessage;

class Log : public QObject
{
    Q_OBJECT

public:
    static Log & getInstance(bool showFile = false, bool showFunction = false, bool showLineNumber = false);
    Q_INVOKABLE void logInfoUser(QString s);
    static void logCallbackForHardware(uint8_t mt, std::string msg);
    static void excludeRegExp(QRegExp exp);
    static const QString path;
    static const QString wcPath;
    static const QString logsFolder;
    static const QString dateFormat;

    enum HardwareLogType{
        Info=1,
        Debug=2,
        Warning=3,
        Critical=4
    };

signals:
    void beginAppendMsg(LogMessage message);
    void endAppendMsg();

public slots:

protected:
    explicit Log(QObject *parent = nullptr, bool showFile = false, bool showFunction = false, bool showLineNumber = false);

private:
    static Log* theOneTrueInstance;
    static QMutex mutex;
    // Exclusions
    static QList<QRegExp> mExclusions;
    // Smart pointers to log files
    QScopedPointer<QFile> mLogFile;
    QScopedPointer<QFile> mWCLogFile;
    QHash<Qt::HANDLE,int> mThreads;
    // Settings
    const bool mShowFile;
    const bool mShowFunction;
    const bool mShowLineNumber;
    // Current file directory
    const QDir cdir = QDir("./");

    // Helpers
    static bool isExcluded(const QString msg);
    static void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    static void archiveLogFiles();
    static void archive();
    static void clearArchives();
    static void archiveLogsFolder();
};

class LogMessage
{
public:
    LogMessage();

    QDateTime dateTime;
    int threadNumber;
    QString type;
    QString category;
    QString msg;
    QString file;
    QString function;
    int lineNumber;

};

void registerTypesToQt();

} // QtLog

Q_DECLARE_METATYPE(QtLog::LogMessage);

#endif // LOG_H
