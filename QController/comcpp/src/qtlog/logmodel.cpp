#include "logmodel.h"
#include "logfilemodel.h"

#include <QGuiApplication>

QtLog::LogModel::LogModel(QObject *parent)
    : LogModelBase(parent)
{
    // Set up timer
    mBufferWatcher = QTimerPtr(new QTimer(this));
    mBufferWatcher->setInterval(BUFFER_WATCH_INTERVAL_MS);
    connect(mBufferWatcher.data(),&QTimer::timeout,this,&LogModel::bufferWatch);
    mBufferWatcher->start();

    beginResetModel();

    // Read in the current contents of the log file    
    QString logPath = QGuiApplication::applicationDirPath() + QDir::separator() + Log::path;
    QStringList l = Utils::readFileToQStringList(logPath);
    for ( QString s : l  )
    {
        mList.append(LogFileModel::logMessageFromString(s));
    }

    QFile* file = new QFile(logPath);
    if (file->exists()) {
        file->open(QIODevice::ReadOnly | QFile::Text);
        QTextStream textStream(file);
        textStream.setCodec("Windows-1251");
        QString s = textStream.readLine();
        while (!s.isNull()) {
            mList.append(LogFileModel::logMessageFromString(s));
            s = textStream.readLine();
        }
    }

    connect(&Log::getInstance(), &Log::beginAppendMsg, this, [=](LogMessage message) {
        mBuffer.append(message);
    });

    endResetModel();
}


void QtLog::LogModel::addMessages(QList<LogMessage> messages)
{
    if (messages.isEmpty())
        return;

    beginInsertRows(QModelIndex(),mList.size(),mList.size() + messages.size() - 1);

    for (LogMessage msg : messages) {
        mList.append(msg);
    }

    endInsertRows();

    if (mList.size() > MAX_DISPLAYED)
        removeFirstMessages(MAX_DISPLAYED - mList.size());
}

void QtLog::LogModel::removeFirstMessages(int count)
{
    if (count <= 0 || count >= mList.size())
        return;

    beginRemoveRows(QModelIndex(),0,count - 1);

    for( int i = 0; i < count; i ++ )
        mList.takeFirst();

    endRemoveRows();

}

void QtLog::LogModel::flushModel()
{
    beginResetModel();

    mList.clear();

    endResetModel();
}

void QtLog::LogModel::bufferWatch()
{
    addMessages(mBuffer);
    mBuffer.clear();
}
