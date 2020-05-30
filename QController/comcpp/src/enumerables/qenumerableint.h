#ifndef QENUMERABLEINT_H
#define QENUMERABLEINT_H

#include <QObject>
#include "enumerable.h"

class QEnumerableInt : public QObject, public Enumerable<int>
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE requestChange NOTIFY valueChanged)
    Q_PROPERTY(int max READ max CONSTANT)
    Q_PROPERTY(int min READ min CONSTANT)
    Q_PROPERTY(double valPerc READ valPerc NOTIFY valueChanged)

public:
    explicit QEnumerableInt(QObject *parent = nullptr) : QObject(parent), Enumerable<int>() { }
    explicit QEnumerableInt(const int& value, QObject *parent = nullptr) : QObject(parent), Enumerable<int>(value) { }
    virtual ~QEnumerableInt() { }

    // Setters
    void setValue(int val);

signals:
    // Informs other objects that the value had changed
    void valueChanged(int value);

public slots:
    // From GUI
    void plus(int n = 1) { requestChangeP(QEnumerableInt::nextValue(n)); }
    void minus(int n = 1) { requestChangeP(QEnumerableInt::prevValue(n)); }
    void requestChange(int val) { requestChangeP(valueIfSet(val)); }

protected:
    // Helpers
    virtual void requestChangeP(int val) { setValue(val); }
};

#endif // QENUMERABLEINT_H
