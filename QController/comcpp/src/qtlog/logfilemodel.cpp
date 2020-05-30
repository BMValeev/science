#include "logfilemodel.h"

QtLog::LogFileModel::LogFileModel(QObject *parent)
    : LogModelBase (parent)
    , mLogFile(nullptr)
{
}

QtLog::LogMessage QtLog::LogFileModel::logMessageFromString(QString line)
{
    LogMessage msg;

    QString datetime = line.mid(0,Log::dateFormat.length());
    msg.dateTime = QDateTime::fromString(datetime,
                                         Log::dateFormat);
    msg.threadNumber = line.mid(24,1).toInt();
    msg.type = line.mid(26,3);
    msg.category = line.mid(29,4);
    QStringList msgAndCallee = line.mid(32).split(" ");
    QString callee = msgAndCallee.last();
    msgAndCallee.removeLast();
    msg.msg = msgAndCallee.join(" ");
    QRegExp crxp("^\\[([^|]*)\\|([^|]*)\\|([^|]*)\\]$");
    crxp.indexIn(callee);
    QStringList callees = crxp.capturedTexts();
    if (callees.size() == 4) {
        msg.file = callees[1];
        msg.function = callees[2];
        msg.lineNumber = callees[3].toInt();
    }

    return msg;
}

int QtLog::LogFileModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mLogFile || (mLogFile.data() == nullptr))
        return 0;

    return mRowCount;
}

QString QtLog::LogFileModel::source() const
{
    if (mLogFile.data() != nullptr)
        return mLogFile->fileName();

    return "";
}

void QtLog::LogFileModel::setSource(QString source)
{
    if (mLogFile.data() != nullptr) {
        if (mLogFile->fileName() == source)
            return;
    }

    // If "", we set no file, the model should be empty
    if (source == "") {
        flushModel();
        return;
    }

    // Do nothing if there is no such file
    QFile* file = new QFile(source);
    if (!file->exists()) {
        return;
    }

    beginResetModel();

    // Set the logging file
    // check which a path to file you use
    mLogFile.reset(file);
    // Open the file logging
    mLogFile.data()->open(QIODevice::ReadOnly | QIODevice::Append | QFile::Text);
    mRowCount = countRows();

    endResetModel();

    emit sourceChanged(mLogFile->fileName());
}

void QtLog::LogFileModel::flushModel()
{
    beginResetModel();

    // Disconnect, just in case
    if (mLogFile.data())
        mLogFile->disconnect(this);

    // Reset the model to an undefined file
    mLogFile.reset(nullptr);
    mRowCount = 0;

    endResetModel();

    emit sourceChanged("");
}

int QtLog::LogFileModel::countRows()
{
    if (!mLogFile)
        return 0;

    QTextStream stream(mLogFile.data());
    stream.setCodec("Windows-1251");

    int c = 0;
    QString line;
    stream.seek(0);
    line = stream.readLine();
    while (!line.isNull()) {
        c++;
        line = stream.readLine();
    }
    stream.seek(0);
    return c;
}

QtLog::LogMessage QtLog::LogFileModel::readRow(int index) const
{
    if (!mLogFile)
        return LogMessage();

    static int lastIndex = 0;
    static int lastPos = 0;

    MQTextStream stream(mLogFile.data());
    stream.setCodec("Windows-1251");
    //cout << " " << index << endl;

    // row string, s - helper string
    QString row;
    // stringlist for last rows
    //QStringList l;
    // number of last characters to load
    //int k = 200;

    // indexes difference
    int idiff = index - lastIndex;
    // Update internal variables
    lastIndex = index;

    // last stream position
    stream.seek(lastPos);

    if (idiff==0) {
        // The same index was requested
        row = stream.readLine();
        return LogFileModel::logMessageFromString(row);
    } else if (idiff > 0) {
        // We need a row that is later than the last in the file
        while (idiff > 0) {
            // Move forward
            idiff--;
            stream.readLine();
        }
        lastPos = stream.pos();
        row = stream.readLine();
        return LogFileModel::logMessageFromString(row);
    } else if (idiff < 0 && abs(idiff) > index ) {
        // Reset statics as if we go from the begining
        lastIndex = 0;
        lastPos = 0;
        idiff = index;
        stream.seek(lastPos);
        // Now, as in the case above, we need a row
        // that is later than the last in the file
        while (idiff > 0) {
            // Move forward
            idiff--;
            stream.readLine();
        }
        lastIndex = index;
        lastPos = stream.pos();
        row = stream.readLine();
        return LogFileModel::logMessageFromString(row);
    } else {
        // Skip last \n character
        if (stream.pos() > 0)
            stream.seek(stream.pos() - 1);
        // Read back
        while (abs(idiff)-1 > 0) {
            // Move back
            idiff++;
            stream.readLineBack();
            if (stream.pos() > 0)
                stream.seek(stream.pos() - 1);
        }
        row = stream.readLineBack();
        lastPos = stream.pos();
        return LogFileModel::logMessageFromString(row);
    }
    return LogMessage();

}
