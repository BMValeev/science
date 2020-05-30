#ifndef QENUMERABLESTRING_H
#define QENUMERABLESTRING_H

#include <QObject>
#include "enumerable.h"

class QEnumerableString : public QObject, public Enumerable<QString>
{
    Q_OBJECT
    Q_PROPERTY(QString value READ value WRITE requestChange NOTIFY valueChanged)
    Q_PROPERTY(QString max READ max CONSTANT)
    Q_PROPERTY(double valPerc READ valPerc NOTIFY valueChanged)

public:
    explicit QEnumerableString(QObject *parent = nullptr) : QObject(parent), Enumerable<QString>() { }
    explicit QEnumerableString(const QString& value, QObject *parent = nullptr) : QObject(parent), Enumerable<QString>(value) { }
    virtual ~QEnumerableString() { }

    // Setters
    void setValue(QString val);

signals:
    // Informs other objects that the value had changed
    void valueChanged(QString value);

public slots:
    // From GUI
    void plus(int n = 1) { requestChangeP(QEnumerableString::nextValue(n)); }
    void minus(int n = 1) { requestChangeP(QEnumerableString::prevValue(n)); }
    void requestChange(QString val) { requestChangeP(valueIfSet(val)); }

protected:
    // Helpers
    virtual void requestChangeP(QString val) { setValue(val); }
};

#endif // QENUMERABLESTRING_H
