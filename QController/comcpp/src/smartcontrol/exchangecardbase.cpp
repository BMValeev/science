#include "exchangecardbase.h"

QList<Record>* ExchangeCardBase::records = nullptr;

Record* ExchangeCardBase::get(uint16_t id)
{
    if (records == nullptr)
    {
        qFatal("ExchangeCard can't be used without initialization of records");
    }

    for (auto& rec : *records) {
        if (rec.id() == id)
            return &rec;
    }

    // id not found
    qWarning() << "there is no record with id=" << id;
    return nullptr;
}
