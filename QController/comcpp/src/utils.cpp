#include "utils.h"
#include "type_traits"

//#include <QDataStream>
#include <QEventLoop>
#include <QTimer>

uint32_t Utils::uint32FromQByteArray(QByteArray data)
{
    Q_ASSERT(data.size()>=4);

    uint32_t value = (static_cast<uint32_t>(data[0]) & 0x000000FF) +
            ((static_cast<uint32_t>(data[1]) << 8) & 0x0000FF00) +
            ((static_cast<uint32_t>(data[2]) << 16) & 0x00FF0000) +
            ((static_cast<uint32_t>(data[3]) << 24) & 0xFF000000);

    return value;
}

uint16_t Utils::uint16FromQByteArray(QByteArray data)
{
    Q_ASSERT(data.size()>=2);

    uint16_t value = (static_cast<uint16_t>(data[0]) & 0x00FF) +
            ((static_cast<uint16_t>(data[1]) << 8) & 0xFF00);

    return value;
}

QList<int> Utils::stringToIntList(QStringList list)
{
    // Transform to integers
    QList<int> ints;
    for( int i=0; i<list.count(); ++i )
    {
        ints.append(list.at(i).toInt());
    }
    return ints;
}

QList<float> Utils::stringToFloatList(QStringList list)
{
    // Transform to integers
    QList<float> ints;
    for( int i=0; i<list.count(); ++i )
    {
        ints.append(list.at(i).toFloat());
    }
    return ints;
}

void Utils::storeIntAsUint16(uint8_t *data, int value)
{
    uint16_t v = static_cast<uint16_t>(value);
    data[0] = v & 0xFF;
    data[1] = (v >> 8) & 0xFF;
}

void Utils::storeIntAsUint16(QVector<uint8_t>& data, int value, bool prepend)
{
    uint16_t v = static_cast<uint16_t>(value);
    if (prepend) {
        data.prepend((v >> 8) & 0xFF);
        data.prepend(v & 0xFF);
    } else {
        data.append(v & 0xFF);
        data.append((v >> 8) & 0xFF);
    }
}

void Utils::storeIntAsUint16(QByteArray& data, int value, bool prepend)
{
    uint16_t v = static_cast<uint16_t>(value);
    char* cp = reinterpret_cast<char*>(&v);
    if (prepend) {
        data.prepend(*(cp+1));
        data.prepend(*cp);
    } else {
        data.append(*cp);
        data.append(*(cp+1));
    }
}

bool Utils::makeSureThereIsFile(QString path)
{
    QFileInfo fi(path);
    // Check if the file is there, otherwise create empty file
    if (!(fi.exists() && fi.isFile())) {
        QFile file(path);
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            return false;
        }
    }
    return true;
}

bool Utils::makeSureThereIsFolder(QString path)
{
    QFileInfo fi(path);
    // Check if the file is there, otherwise create empty file
    if (!(fi.exists() && fi.isDir())) {
        QDir().remove(path);
        if (!QDir().mkdir(path)) {
            return false;
        }
    }
    return true;
}

bool Utils::removeFileOrDir(QString path)
{
    QFileInfo fi(path);

    if (!fi.exists())
        return true;

    if (fi.isDir())
        return QDir(path).removeRecursively();

    if (fi.isFile())
        return QFile(path).remove();

    return false;
}

// Reset configuration file
bool Utils::correctPermissions(QString path)
{
    QFileInfo fi(path);
    // Check access rights
    if (!fi.isWritable()) {
        // Add rights to write
        if (!QFile::setPermissions(path, QFileDevice::WriteOwner | QFileDevice::ReadOwner )) {
            qWarning() << "failed to set the write permissions to " + path;
            return false;
        }
    }
    return true;
}

bool Utils::copyDirRecursively(QString sourceDir, QString destDir)
{
    bool success = true;

    QDir source(sourceDir);
    if(!source.exists())
        return false;

    QDir dest(destDir);
    if(!dest.exists())
        dest.mkdir(destDir);

    QStringList files = source.entryList(QDir::Files);
    for(auto& file: files) {
        QString srcName = sourceDir + QDir::separator() + file;
        QString destName = destDir + QDir::separator() + file;
        success = success && QFile::copy(srcName, destName);
        correctPermissions(destName);
    }

    files.clear();
    files = source.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    for(auto& file: files)
    {
        QString srcName = sourceDir + QDir::separator() + file;
        QString destName = destDir + QDir::separator() + file;
        success = success && copyDirRecursively(srcName, destName);
    }

    return success;
}

qint64 Utils::dirSize(QString dirPath, QStringList nameFilters) {
    qint64 size = 0;
    QDir dir(dirPath);
    if (!dir.exists())
        return 0;
    //calculate total size of current directories' files
    QDir::Filters fileFilters = QDir::Files|QDir::System|QDir::Hidden;
    dir.setFilter(fileFilters);
    dir.setNameFilters(nameFilters);
    for(QString filePath : dir.entryList()) {
        QFileInfo fi(dir, filePath);
        size+= fi.size();
    }
    //add size of child directories recursively
    QDir::Filters dirFilters = QDir::Dirs|QDir::NoDotAndDotDot|QDir::System|QDir::Hidden;
    for(QString childDirPath : dir.entryList(dirFilters))
        size+= dirSize(dirPath + "/" + childDirPath,nameFilters);
    return size;
}

QString Utils::formatSize(qint64 size) {
    QStringList units = {"Bytes", "KB", "MB", "GB", "TB", "PB"};
    int i;
    double outputSize = size;
    for(i=0; i<units.size()-1; i++) {
        if(outputSize<1024) break;
        outputSize= outputSize/1024;
    }
    return QString("%0 %1").arg(outputSize, 0, 'f', 2).arg(units[i]);
}

void Utils::archiveFolder(QString folderPath, QString archiveName, bool removeFiles)
{
    QProcess process;
    QStringList args;
    args << "-zcvf"
         << archiveName
         << folderPath.remove(QRegExp("^\\.\\/"));

    if (removeFiles)
        args.append("--remove-files");
    process.start("tar", args);
    process.waitForStarted();
    process.waitForFinished();
}

QStringList Utils::readFileToQStringList(QString filePath, QTextCodec* codec)
{
    QStringList list;
    // Read in the current contents of the log file
    QFile* file = new QFile(filePath);
    if (file->exists()) {
        file->open(QIODevice::ReadOnly | QFile::Text);
        QTextStream textStream(file);
        textStream.setCodec(codec);
        QString s = textStream.readLine();
        while (!s.isNull()) {
            list.append(s);
            s = textStream.readLine();
        }
    } else {
        qWarning() << "There is no such file to read - " << filePath;
    }
    return list;
}

QVector<bool> Utils::jsonListToBool(QList<QJsonValue> jsl)
{
    QVector<bool> l;
    l.reserve(jsl.size());
    for (auto& value : jsl)
    {
        l.append(value.toBool());
    }
    return l;
}

QVector<double> Utils::jsonListToDouble(QList<QJsonValue> jsl)
{
    QVector<double> l;
    l.reserve(jsl.size());
    for (auto& value : jsl)
    {
        l.append(value.toDouble());
    }
    return l;
}

QStringList Utils::jsonListToString(QList<QJsonValue> jsl)
{
    QStringList l;
    l.reserve(jsl.size());
    for (auto& value : jsl)
    {
        l.append(value.toString());
    }
    return l;
}

QVector<QJsonArray> Utils::jsonListToArray(QList<QJsonValue> jsl)
{
    QVector<QJsonArray> l;
    l.reserve(jsl.size());
    for (auto& value : jsl)
    {
        l.append(value.toArray());
    }
    return l;
}

QVector<QJsonObject> Utils::jsonListToObject(QList<QJsonValue> jsl)
{
    QVector<QJsonObject> l;
    l.reserve(jsl.size());
    for (auto& value : jsl)
    {
        l.append(value.toObject());
    }
    return l;
}

QVector<int> Utils::jsonListToInt(QList<QJsonValue> jsl)
{
    QVector<int> l;
    l.reserve(jsl.size());
    for (auto& value : jsl)
    {
        l.append(value.toInt());
    }
    return l;
}

QVector<int> Utils::jsonArrayToInt(QJsonArray array)
{
    QVector<int> l;
    l.reserve(array.size());
    for( int i=0; i < array.size(); ++i)
    {
        l.append(array[i].toInt());
    }
    return l;
}

QStringList Utils::jsonArrayToString(QJsonArray array, QString defaultValue)
{
    QStringList l;
    l.reserve(array.size());
    for( int i=0; i < array.size(); ++i)
    {
        l.append(array[i].toString(defaultValue));
    }
    return l;
}

int Utils::jsonSearchLargerInt(QJsonArray array, int value)
{
    if (array.isEmpty())
        return 0;

    // Iterate and search next one that is larger
    int v;
    for( int i=0; i < array.size(); ++i)
    {
        v = array[i].toInt(array.first().toInt(0));
        if (v > value) {
            return v;
        }
    }
    return array.first().toInt(0);
}

int Utils::jsonSearchSmallerInt(QJsonArray array, int value)
{
    if (array.isEmpty())
        return 0;

    // Value is not found, iterate and search next one that is smaller
    int v;
    for( int i=array.size()-1; i >= 0; --i)
    {
        v = array[i].toInt(array.first().toInt(0));
        if (v < value) {
            return v;
        }
    }
    return array.first().toInt(0);
}

void Utils::sleep_ms(int ms)
{
#ifdef Q_OS_WIN
    Sleep(uint(ms));
#else
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, nullptr);
#endif
}

template<typename T>
T Utils::jsonValueTo(QJsonValue v)
{
    Q_UNUSED(v)
    Q_ASSERT(false); // type not implemented
}

template<>
int Utils::jsonValueTo<int>(QJsonValue v) { return v.toInt(0); }
template<>
float Utils::jsonValueTo<float>(QJsonValue v) { return static_cast<float>(v.toDouble(0)); }
template<>
double Utils::jsonValueTo<double>(QJsonValue v) { return v.toDouble(0); }
template<>
QString Utils::jsonValueTo<QString>(QJsonValue v) { return v.toString(""); }

bool Utils::asyncWait(int ms, QObject *object, const char * signal)
{
    QEventLoop loop;
    QTimer timer;

    timer.setSingleShot(true);
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    QObject::connect(object, signal, &loop, SLOT(quit()));

    timer.start(ms);
    loop.exec();

    if (timer.isActive()) {
        // ended before timer stopped
        timer.stop();
        return true;
    } else {
        // timeout
        return false;
    }
}
