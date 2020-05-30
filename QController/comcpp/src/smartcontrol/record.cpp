#include "record.h"

Record::Record(const Record &rec) : Record(rec.mData.bytes) {}

Record &Record::operator=(const Record &rec)
{
    mData = rec.mData;
    return *this;
}

Record::~Record() {}

void Record::serialize(std::vector<uint8_t> &buff) const
{
    buff.insert(buff.end(), &mData.bytes[0], &mData.bytes[20]);
}

void Record::serialize(QByteArray& buff) const
{
    buff.append(reinterpret_cast<const char*>(mData.bytes), 20);
}

void Record::serializeValue(std::vector<uint8_t> &buff) const
{
    buff.insert(buff.end(), &mData.bytes[3], &mData.bytes[7]);
}

void Record::serializeValue(QByteArray &buff) const
{
    buff.append(reinterpret_cast<const char*>(mData.bytes + 3), 4);
}

void Record::serializeIdValue(std::vector<uint8_t> &buff) const
{
    buff.insert(buff.end(), &mData.bytes[0], &mData.bytes[2]);
    buff.insert(buff.end(), &mData.bytes[3], &mData.bytes[7]);
}

void Record::serializeIdValue(QByteArray &buff) const
{
    buff.append(reinterpret_cast<const char*>(mData.bytes), 2);
    buff.append(reinterpret_cast<const char*>(mData.bytes + 3), 4);
}

void Record::serializeNoId(std::vector<uint8_t> &buff) const
{
    buff.insert(buff.end(), &mData.bytes[2], &mData.bytes[20]);
}

void Record::serializeNoId(QByteArray &buff) const
{
    buff.append(reinterpret_cast<const char*>(&mData.bytes[2]), 18);
}

QDataStream &operator<<(QDataStream &out, const Record &r) {
    out.writeRawData(r.bytes(), 20);
    return out;
}

QDataStream &operator>>(QDataStream &in, Record &r) {
    char rawData[20];
    in.readRawData(rawData, 20);
    r = Record(rawData);
    return in;
}
