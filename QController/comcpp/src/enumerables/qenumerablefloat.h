#ifndef QENUMERABLEFLOAT_H
#define QENUMERABLEFLOAT_H

#include <QObject>
#include "enumerable.h"

class QEnumerableFloat : public QObject, public Enumerable<float>
{
    Q_OBJECT
    Q_PROPERTY(float value READ value WRITE requestChange NOTIFY valueChanged)
    Q_PROPERTY(float max READ max CONSTANT)
    Q_PROPERTY(double valPerc READ valPerc NOTIFY valueChanged)

public:
    explicit QEnumerableFloat(QObject *parent = nullptr) : QObject(parent), Enumerable<float>() { }
    explicit QEnumerableFloat(const float& value, QObject *parent = nullptr) : QObject(parent), Enumerable<float>(value) { }
    virtual ~QEnumerableFloat() { }

    // Setters
    void setValue(float val);

signals:
    // Informs other objects that the value had changed
    void valueChanged(float value);

public slots:
    // From GUI
    void plus(int n = 1) { requestChangeP(QEnumerableFloat::nextValue(n)); }
    void minus(int n = 1) { requestChangeP(QEnumerableFloat::prevValue(n)); }
    void requestChange(float val) { requestChangeP(valueIfSet(val)); }

protected:
    // Helpers
    virtual void requestChangeP(float val) { setValue(val); }
};

#endif // QENUMERABLEFLOAT_H
