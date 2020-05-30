#ifndef MQTEXTSTREAM_H
#define MQTEXTSTREAM_H

#include <QFile>
#include <QTextStream>

class MQTextStream : public QTextStream {

public:
    MQTextStream (QFile* file);
    QString readLineBack(qint64 maxlen = 0);
};


#endif // MQTEXTSTREAM_H
