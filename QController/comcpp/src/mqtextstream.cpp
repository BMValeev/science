#include "mqtextstream.h"

MQTextStream::MQTextStream(QFile *file)
    : QTextStream(file)
{
}

QString MQTextStream::readLineBack(qint64 maxlen)
{
    if (this->pos() == 0)
        return QString();

    QString ch;

    if (this->pos() == 1) {
        this->seek(0);
        ch = this->read(1);
        if (ch == "\n")
            return QString("");
        else
            return ch;
    }

    QString s = "";


    this->seek(this->pos()-1);
    ch = this->read(1);

    while (ch != "\n" && this->pos() > 0)
    {
        s.prepend(ch);
        this->seek(this->pos()-2);
        ch = this->read(1);
        if (s.count() >= maxlen && maxlen != 0)
            break;
    }
    return s;

    /*int k = 1;
    int pos = this->pos();
    this->seek(pos-k);
    ch = this->read(k);

    while (!ch.contains("\n")  && this->pos() > 0)
    {
        k++;
        this->seek(pos-k);
        ch = this->read(k);
        if (ch.count() >= maxlen && maxlen != 0)
            break;
        if (ch.contains("й")) {
            cout << ch.data() << endl;
        }
        if (ch.count() > 1 && ch.endsWith("\n")) {
            ch = ch.replace("\n","");
        }
    }
    this->seek(this->pos()-k+1);
    return ch.replace("\n","");
    */
}
