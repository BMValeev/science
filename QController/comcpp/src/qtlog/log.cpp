#include "log.h"

#include <QCoreApplication>
#include <QQmlEngine>

#include "logfilemodel.h"
#include "logmodel.h"
#include "logsortfiltermodel.h"

QList<QRegExp> QtLog::Log::mExclusions;
QtLog::Log* QtLog::Log::theOneTrueInstance;
QMutex QtLog::Log::mutex;
const QString QtLog::Log::path = "log.txt";
const QString QtLog::Log::wcPath = "wclog.txt";
const QString QtLog::Log::logsFolder = "logs";
const QString QtLog::Log::dateFormat = "yyyy-MM-dd|hh:mm:ss.zzz";

// Assign data names of categories
Q_LOGGING_CATEGORY(infoAppEvents, " APP")
Q_LOGGING_CATEGORY(infoUser,      "USER")
Q_LOGGING_CATEGORY(debugHardware, "HRDW")
Q_LOGGING_CATEGORY(debugI2CHex,   "I2CH")
Q_LOGGING_CATEGORY(debugSPIHex,   "SPIH")
Q_LOGGING_CATEGORY(debugWarning,  " WRN")
Q_LOGGING_CATEGORY(python,        " PYT")

QtLog::Log& QtLog::Log::getInstance(bool showFile, bool showFunction, bool showLineNumber)
{
    if (!theOneTrueInstance)
        theOneTrueInstance = new Log(nullptr,showFile,showFunction,showLineNumber);
    return *theOneTrueInstance;
}

void QtLog::Log::logInfoUser(QString s)
{
    qInfo(infoUser()) << s;
}

void QtLog::Log::logCallbackForHardware(uint8_t mt, std::string msg)
{
    QString s(msg.data());

    s = s.simplified();

    switch(mt) {
    case Info:
        //qDebug(debugHardware()) << s;
        break;
    case Debug:
        //qDebug(debugHardware()) << s;
        break;
    case Warning:
        //qDebug(debugWarning()) << s;
        break;
    case Critical:
        qCritical() << s;
        break;
    }
}

void QtLog::Log::excludeRegExp(QRegExp exp)
{
    mExclusions.append(exp);
}

QtLog::Log::Log(QObject *parent, bool showFile, bool showFunction, bool showLineNumber)
    : QObject(parent), mShowFile(showFile), mShowFunction(showFunction), mShowLineNumber(showLineNumber)
{
    if (theOneTrueInstance)
        qFatal("Log::Log - instance already exists");

    QString logPath = QCoreApplication::applicationDirPath() + QDir::separator() + path;
    QString wcLogPath = QCoreApplication::applicationDirPath() + QDir::separator() + wcPath;

    QFileInfo fi(logPath);
    // Archive file if it exists
    if (fi.exists() && fi.isFile()) {
        archiveLogFiles();
    }

    // Set the logging files
    // check which a path to file you use
    mLogFile.reset(new QFile(logPath));
    mWCLogFile.reset(new QFile(wcLogPath));
    // Open the files for logging
    mLogFile.data()->open(QIODevice::ReadWrite | QIODevice::Append | QFile::Text);
    mWCLogFile.data()->open(QIODevice::ReadWrite | QIODevice::Append | QFile::Text);
    // Set handler
    qInstallMessageHandler(messageHandler);

    theOneTrueInstance = this;

    // Archive "logs" folder & free space if needed
    archive();
}

bool QtLog::Log::isExcluded(const QString msg)
{
    for (auto& exp: mExclusions) {
        if (msg.contains("QGridLayoutEngine")) {
            int a = 1;
            a += 1;
        }
        if (exp.exactMatch(msg)) return true;
    }
    return false;
}

void QtLog::Log::archiveLogFiles()
{    
    QString logPath = QCoreApplication::applicationDirPath() + QDir::separator() + path;
    QString wcLogPath = QCoreApplication::applicationDirPath() + QDir::separator() + wcPath;
    QString logsFolderPath = QCoreApplication::applicationDirPath() + QDir::separator() + logsFolder;

    QFileInfo fi(logsFolderPath);
    // Check that we have log subdirectory
    if (!fi.exists()) {
        if (!QDir().mkdir(logsFolderPath)) {
            qWarning() << "failed to create \"" << logsFolderPath << "\" folder";
            return;
        }
    }
    // Check that it is indeed a folder
    if (!fi.isDir()) {
        qWarning() << "the \"" << logsFolderPath << "\" already exists and it is not a folder, removing...";
        if (!QFile::remove(logsFolderPath)) {
            qWarning() << "failed to remove \"" << logsFolderPath << "\"";
            return;
        }
        if (!QDir().mkdir(logsFolderPath)) {
            qWarning() << "failed to create \"" << logsFolderPath << "\" folder";
            return;
        }
    }
    // Archiving
    if (!QFile::copy(logPath, logsFolderPath + QDir::separator() + "log-"+QDateTime::currentDateTime().toString("yyyy-MM-dd|hh:mm:ss.zzz")+".txt")) {
            qWarning() << "failed to archive (copy) the log file";
            return;
    }
    if (!QFile::remove(logPath)) {
            qWarning() << "failed to remove old log file";
            return;
    }
    if (!QFile::copy(wcLogPath, logsFolderPath + QDir::separator() + "wclog-"+QDateTime::currentDateTime().toString("yyyy-MM-dd|hh:mm:ss.zzz")+".txt")) {
            qWarning() << "failed to archive (copy) the wclog file";
            return;
    }
    if (!QFile::remove(wcLogPath)) {
            qWarning() << "failed to remove old wclog file";
            return;
    }
}

void QtLog::Log::archive()
{
    QString logsFolderPath = QCoreApplication::applicationDirPath() + QDir::separator() + logsFolder;

    qint64 logsSize = Utils::dirSize(logsFolderPath);
    qInfo() << "<==== the size of the \"logs\" folder is" << Utils::formatSize(logsSize);
    archiveLogsFolder();

    qint64 archsSize = Utils::dirSize("./",QStringList() << "archlog-*");
    qInfo() << "<==== the size of the log archives is" << Utils::formatSize(archsSize);
    clearArchives();
}

void QtLog::Log::clearArchives()
{
    qint64 archsSize = Utils::dirSize("./",QStringList() << "archlog-*");
    QDir dir("./");
    dir.setNameFilters(QStringList() << "archlog-*");
    dir.setFilter(QDir::Files|QDir::System|QDir::Hidden);
    dir.setSorting(QDir::Time|QDir::DirsFirst);
    QStringList el;
    while ((archsSize>>24) > MAX_ARCHIVES_SIZE_MB) {
        // Get the file list
        el = dir.entryList();
        // Delete last element
        if (el.isEmpty()) {
            qCritical() << "Failed to clear archives - entry list shouldn't be empty";
            return;
        }
        qInfo() << "Removing " << el.last();
        if (!QFile::remove(el.last())) {
            qCritical() << "Failed to clear archives - failed to remove " << el.last();
            return;
        }
        dir.refresh();
        archsSize = Utils::dirSize("./",QStringList() << "archlog-*");
    }
}

void QtLog::Log::archiveLogsFolder()
{
    QString logsFolderPath = QCoreApplication::applicationDirPath() + QDir::separator() + logsFolder;

    qint64 size = Utils::dirSize(logsFolderPath);

    if ((size>>24) < MAX_LOGSFOLDER_SIZE_MB)
        return;

    qInfo() << "  <== archiving";
    Utils::archiveFolder(logsFolderPath,
                         "archlog-" + QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss-zzz") + ".tar.gz");
}

// The implementation of the handler
void QtLog::Log::messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Log *log = &Log::getInstance();

    QString s;
    LogMessage lm;

    // Open stream file writes
    QTextStream out(&s);
    // Write the date of recording
    lm.dateTime = QDateTime::currentDateTime();
    out << lm.dateTime.toString(dateFormat);
    Qt::HANDLE th = QThread::currentThreadId();
    if (!log->mThreads.contains(th))
        log->mThreads[th] = log->mThreads.size();

    lm.threadNumber = log->mThreads.value(th,0);
    out << "(" << lm.threadNumber << ")";

    // By type determine to what level belongs message
    switch (type)
    {
        case QtInfoMsg:     lm.type = "INF"; break;
        case QtDebugMsg:    lm.type = "DBG"; break;
        case QtWarningMsg:  lm.type = "WRN"; break;
        case QtCriticalMsg: lm.type = "CRT"; break;
        case QtFatalMsg:    lm.type = "FTL"; break;
    }
    out << lm.type;
    // Write to the output category of the message
    lm.category = QString("default").compare(context.category)? context.category : "";
    out.setFieldWidth(3);
    out << lm.category;
    out.setFieldWidth(0);

    // Space before what's coming
    out  << " ";

    // Print message itself
    lm.msg = msg.simplified().replace(QRegExp("^\"(.*)\"$"), "\\1");

    // Check exclusions
    if (isExcluded(lm.msg)) return;

    out << lm.msg;

#ifdef QT_DEBUG
    // Print file, function and line number (only in debug build)
    if (log->mShowFile) {
        lm.file = log->cdir.relativeFilePath(QString(context.file));
        out << " [" + lm.file.remove(0,3);
    }

    if (log->mShowFunction) {
        lm.function = QString(context.function);
        out << (log->mShowFile? "|" : " [");
        out << lm.function.remove(QRegExp("\\(.*\\)")).split(" ").last();
    }

    if (log->mShowLineNumber) {
        lm.lineNumber = context.line;
        out << (log->mShowFile || log->mShowFunction? "|" : " [");
        out << QString::number(lm.lineNumber);
    }

    if (log->mShowFile || log->mShowFunction || log->mShowLineNumber)
        out  << "]";

    out << endl;
#endif

    // Write to console
    QTextStream conout(stdout);
    conout << s;
    conout.flush();    // Clear the buffered data
    // Write to file
    QMutexLocker locker(&Log::mutex);

    emit log->beginAppendMsg(lm);
    QTextStream fileout(log->mLogFile.data());
    fileout.setCodec("Windows-1251");
    fileout << s;
    fileout.flush();    // Clear the buffered data
    emit log->endAppendMsg();
    // Write warning, critical and fatal errors to a separate file
    if (type == QtWarningMsg || type == QtCriticalMsg || type == QtFatalMsg) {
        QTextStream fileout(log->mWCLogFile.data());
        fileout.setCodec("Windows-1251");
        fileout << s;
        fileout.flush();    // Clear the buffered data
    }
}

QtLog::LogMessage::LogMessage()
{
    dateTime = QDateTime();
    threadNumber = 0;
    type = "";
    category = "";
    msg = "";
    file = "";
    function = "";
    lineNumber = 0;
}

void QtLog::registerTypesToQt()
{
    qRegisterMetaType<QtLog::LogMessage>();
    qmlRegisterUncreatableType<QtLog::Log>("QtLog::Log",1,0,"qtlog", "QtLog::Log should not be created in QML");
    qmlRegisterType<QtLog::LogModel>("QtLog::LogModel",1,0,"qtlog");
    qmlRegisterType<QtLog::LogFileModel>("QtLog::LogFileModel",1,0,"qtlog");
    qmlRegisterType<QtLog::LogSortFilterProxyModel>("QtLog::LogSortFilterProxyModel",1,0,"qtlog");
}
