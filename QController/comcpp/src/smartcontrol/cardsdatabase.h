#ifndef CARDSDATABASE_H
#define CARDSDATABASE_H

#include <QMap>

#include "scdefs.h"
#include "record.h"

class CardsDataBase
{
public:
    struct RecordEntry {
        const QString name;
        const QString description;
        const Record record;
        const bool profiled;

        RecordEntry operator=(const RecordEntry& r) { return RecordEntry(r.name, r.description, r.record, r.profiled); }

        RecordEntry() : record(0, SCDefs::defBoolData), profiled(false) { }
        RecordEntry(const QString& name,
                    const QString& description,
                    const Record& record,
                    const bool profiled)
            : name(name),
              description(description),
              record(record),
              profiled(profiled)
        { }
    };

    static RecordEntry getEntry(SCDefs::DeviceTypes type, uint16_t id);
    static QMapIterator<uint16_t, RecordEntry> getEntryIterator(SCDefs::DeviceTypes type);


private:
    static QMap<SCDefs::DeviceTypes, QMap<uint16_t, RecordEntry>> mData;

};

#endif // CARDSDATABASE_H
