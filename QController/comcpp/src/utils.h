#ifndef UTILS_H
#define UTILS_H

#include <QDebug>
#include <QByteArray>
#include <QDir>
#include <QProcess>
#include <QTextCodec>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QMetaEnum>

#ifdef Q_OS_WIN
#include <WinSock2.h>
#include <windows.h> // for Sleep
#endif

namespace Utils
{

// Sleep
void sleep_ms(int ms);
// Search
template<typename T>
T searchSmaller(QList<T>& list, T value)
{
    if (list.empty())
        return 0;

    // Value is not found, iterate and search next one that is smaller
    for( int i=list.size()-1; i >= 0; --i)
    {
        if (list[i] < value) {
            return list[i];
        }
    }
    return T();
}
template<typename T>
T searchLarger(QList<T>& list, T value)
{
    if (list.empty())
        return 0;

    // Iterate and search next one that is larger
    for( int i=0; i < list.size(); ++i)
    {
        if (list[i] > value) {
            return list[i];
        }
    }
    return T();
}
template<typename T>
T searchSmaller(QVector<T>& list, T value)
{
    QList<T> l = QList<T>::fromVector(list);
    return searchSmaller(l, value);
}
template<typename T>
T searchLarger(QVector<T>& list, T value)
{
    QList<T> l = QList<T>::fromVector(list);
    return searchLarger(l, value);
}
// Conversions
template<typename Tout, typename Tin>
QVector<Tout> qvectorTypeConversion(QVector<Tin> in)
{
    QVector<Tout> out;
    out.reserve(in.size());
    for(auto &t: in)
        out.append(Tout(t));
    return out;
}
// QByteArray conversions
template <typename T>
QVector<T> qvectorFromQByteArray(QByteArray array)
{
    //QDataStream ds(array);
    //QVector<T> vec;
    //ds >> vec;
    //return vec;
    QVector<T> vec(array.size());
    for(int i = 0; i < array.size(); i++) {
        vec[i] = *reinterpret_cast<T*>(array.data() + i);
    }
    return vec;
}
uint32_t uint32FromQByteArray(QByteArray data);
uint16_t uint16FromQByteArray(QByteArray data);
QList<int> stringToIntList(QStringList list);
QList<float> stringToFloatList(QStringList list);
template<typename T> // this can be made with QDataStrean as well
T stringAsT(QString s) { return *reinterpret_cast<T*>(s.toUtf8().data()); }
template<typename T> // this can be made with QDataStrean as well
QString tAsString(T t) { return QString::fromUtf8(reinterpret_cast<char*>(&t)); }
// Storing / serializing
void storeIntAsUint16(uint8_t* data, int value);
void storeIntAsUint16(QVector<uint8_t>& data, int value, bool prepend = false);
void storeIntAsUint16(QByteArray& data, int value, bool prepend = false);
// File system
bool makeSureThereIsFile(QString path);
bool makeSureThereIsFolder(QString path);
bool removeFileOrDir(QString path);
bool correctPermissions(QString path);
qint64 dirSize(QString dirPath, QStringList nameFilters = QStringList());
bool copyDirRecursively(QString sourceDir, QString destDir);
QString formatSize(qint64 size);
void archiveFolder(QString folderPath, QString archiveName, bool removeFiles = true);
QStringList readFileToQStringList(QString filePath, QTextCodec* codec = QTextCodec::codecForName("Windows-1251"));
// Variant
template<typename T>
QVariantList toVariantList(QList<T> list)
{
    QVariantList vl;
    for( int i=0; i<list.count(); ++i )
    {
        vl.append(QVariant(list.at(i)));
    }
    return vl;
}
// Json
QVector<bool> jsonListToBool(QList<QJsonValue> jsl);
QVector<double> jsonListToDouble(QList<QJsonValue> jsl);
QStringList jsonListToString(QList<QJsonValue> jsl);
QVector<QJsonArray> jsonListToArray(QList<QJsonValue> jsl);
QVector<QJsonObject> jsonListToObject(QList<QJsonValue> jsl);
QVector<int> jsonListToInt(QList<QJsonValue> jsl);
QVector<int> jsonArrayToInt(QJsonArray array);
QStringList jsonArrayToString(QJsonArray array, QString defaultValue = "");

template<typename T>
T jsonValueTo(QJsonValue v);
template<>
int jsonValueTo<int>(QJsonValue v);
template<>
double jsonValueTo<double>(QJsonValue v);
template<>
float jsonValueTo<float>(QJsonValue v);
template<>
QString jsonValueTo<QString>(QJsonValue v);


template<typename T>
QList<T> jsonArrayToListOf(QJsonArray array)
{
    QList<T> l;
    l.reserve(array.size());
    for( int i=0; i < array.size(); ++i)
    {
        l.append(jsonValueTo<T>(array[i]));
    }
    return l;
}
template<typename T>
QVector<T> jsonArrayToVectorOf(QJsonArray array)
{
    QVector<T> l;
    l.reserve(array.size());
    for( int i=0; i < array.size(); ++i)
    {
        l.append(jsonValueTo<T>(array[i]));
    }
    return l;
}
int jsonSearchLargerInt(QJsonArray array, int value);
int jsonSearchSmallerInt(QJsonArray array, int value);

bool asyncWait(int ms, QObject *object, const char *signal);

/*template<typename T>
     T jsonValueTo(QJsonValue v)
    {
        if (std::is_same<T,int>::value)
            return _cast<T>(v.toInt(0));
        else if (std::is_same<T,int8_t>::value)
            return _cast<T>(v.toInt(0));
        else if (std::is_same<T,int16_t>::value)
            return _cast<T>(v.toInt(0));
        else if (std::is_same<T,int32_t>::value)
            return _cast<T>(v.toInt(0));
        else if (std::is_same<T,int64_t>::value)
            return _cast<T>(v.toInt(0));
        else if (std::is_same<T,uint>::value)
            return _cast<T>(v.toInt(0));
        else if (std::is_same<T,uint8_t>::value)
            return _cast<T>(v.toInt(0));
        else if (std::is_same<T,uint16_t>::value)
            return _cast<T>(v.toInt(0));
        else if (std::is_same<T,uint32_t>::value)
            return _cast<T>(v.toInt(0));
        else if (std::is_same<T,uint64_t>::value)
            return _cast<T>(v.toInt(0));
        else if (std::is_same<T,double>::value)
            return _cast<T>(v.toDouble(0));
        else if (std::is_same<T,double>::value)
            return _cast<T>(v.toDouble(0));
        else if (std::is_same<T,double>::value)
            return _cast<T>(v.toDouble(0));
        else if (std::is_same<T,bool>::value)
            return _cast<T>(v.toBool(0));
        else if (std::is_same<T,QString>::value)
            return _cast<T>(v.toString());
        else if (std::is_same<T,QVariant>::value)
            return _cast<T>(v.toVariant());
        else {
            Q_ASSERT(false);
            qWarning() << "no conversion from QJsonValue to this type";
            return T();
        }
    }*/

// Q ENUM to string
template<typename QEnum>
QString QtEnumToString (const QEnum value)
{
    return QString(QMetaEnum::fromType<QEnum>().valueToKey(static_cast<int>(value)));
}

};

#endif // UTILS_H
