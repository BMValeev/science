#ifndef EXCHANGECARDBASE_H
#define EXCHANGECARDBASE_H

#include <QVector>
#include <QDebug>

#include "record.h"

class ExchangeCardBase
{
public:
    static QList<Record>* records;
    static Record *get(uint16_t id);
};

#endif // EXCHANGECARDBASE_H
