#ifndef RECORDONDEVICE_H
#define RECORDONDEVICE_H

#include <vector>
#include <QDataStream>

#include "scdefs.h"

union Field
{
    char aValue[4] = {0, 0, 0, 0};
    float fValue;

    // Constructors from different types (how Field created from different types)
    template<typename T>
    Field(const T& value) {
        memcpy(aValue, &value, sizeof(T) < 4? sizeof(T) : 4);
    }
    Field(const float& value) { fValue = value; }
    Field(const double& value) { fValue = static_cast<float>(value); }
    Field(const std::string& value) {
        memcpy(aValue, value.c_str(), value.size() < 4? value.size() : 4);
    }
    Field(const QByteArray& value) {
        memcpy(aValue, value.data(), value.size() < 4? static_cast<ulong>(value.size()) : 4);
    }
    Field(const QString& value) : Field(value.toStdString()) { }

    // Conversion operators (how different types are created from Field)
    template<typename T>
    operator    T()            const { return *reinterpret_cast<const T*>(aValue); }
    operator    float()        const { return fValue; }
    operator    QByteArray()   const { return raw(); }
    operator    std::string()  const { return toStdString(); }
    operator    QString()      const { return toQString(); }
    QByteArray  raw()          const { return QByteArray(aValue, 4); } // all 4 bytes as QByteArray
    std::string toStdString()  const { std::string str(aValue, 4); str.erase(std::find(str.begin(), str.end(), '\0'), str.end()); return str; }
    // QByteArray  toQByteArray() const { std::string str = toStdString(); return QByteArray(str.data()); } // QByteArray-like string
    QString     toQString()    const { std::string str = toStdString(); return QString::fromStdString(str); }
};

class Record
{
public:
    #pragma pack(push, 1) // To make 1 byte aligning
    struct Fields
    {
        uint16_t id;
        SCDefs::DataTypes type;
        Field value;
        Field min;
        Field max;
        Field step;
        SCDefs::Units unit;
    };
    #pragma pack(pop)
    union Data {
        Fields fields;
        char bytes[20];
        Data(const char* data) { for(int i=0; i<20; i++) bytes[i] = data[i]; }
        Data(const uint16_t id, const char* data) { fields.id = id; for(int i=0; i<18; i++) bytes[i+2] = data[i]; }
        template<typename T>
        Data(const uint16_t id,
             const SCDefs::DataTypes type,
             const T value,
             const T min,
             const T max,
             const T step,
             const SCDefs::Units unit)
        {
            fields.id = id;
            fields.type = type;
            fields.value = value;
            fields.min = min;
            fields.max = max;
            fields.step = step;
            fields.unit = unit;
        }
    };

private:
    Data mData;

public:
    Record() : mData(0, SCDefs::defBoolData) {}
    Record(const char* data) : mData(data) {}
    Record(const uint16_t id, const char* data) : mData(id, data) {}
    template<typename T>
    Record(const uint16_t id,
           const SCDefs::DataTypes type,
           const T value,
           const T min,
           const T max,
           const T step,
           const SCDefs::Units unit)
        : mData(id, type, value, min, max, step, unit) {}
    Record(Record const &rec);
    Record& operator=(Record const &rec);
    ~Record();

    // Field getters
    const char * bytes() const { return mData.bytes; }
    uint16_t id() const { return mData.fields.id; }
    SCDefs::DataTypes type() const { return mData.fields.type; }
    SCDefs::Units unit() const { return mData.fields.unit; }
    template<typename T>
    T value() const { return mData.fields.value; }
    template<typename T>
    T min() const { return mData.fields.min; }
    template<typename T>
    T max() const { return mData.fields.max; }
    template<typename T>
    T step() const { return mData.fields.step; }
    // Field setters
    template<typename T>
    void setValue(T value) { mData.fields.value = value; }    
    void setValue(QByteArray a) { memcpy(&mData.fields.value, a.data(), static_cast<std::size_t>(qMin(4, a.size()))); }

    // Serialization
    void serialize(std::vector<uint8_t>& buff) const;
    void serialize(QByteArray& buff) const;
    // Serialize only value - 4 bytes
    void serializeValue(std::vector<uint8_t>& buff) const;
    void serializeValue(QByteArray& buff) const;
    // Serialize only 6 bytes - id + value
    void serializeIdValue(std::vector<uint8_t>& buff) const;
    void serializeIdValue(QByteArray& buff) const;
    // Serialize (without id - only 18 bytes)
    void serializeNoId(std::vector<uint8_t>& buff) const;
    void serializeNoId(QByteArray& buff) const;

    // Checks that the value of one record can be set into another
    bool canSetValueFrom(const Record& r) {
        return ((id() != r.id()) || (type() != r.type()) || (unit() != r.unit()));
    }

};

Q_DECLARE_METATYPE(Record);

// Qt serialization
QDataStream& operator<<(QDataStream& out, const Record& r);
QDataStream& operator>>(QDataStream& in, Record& r);

#endif // BLUETOOTH_H
