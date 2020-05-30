#ifndef QENUMERABLE_H
#define QENUMERABLE_H

#include <QObject>
#include "enumerable.h"

template<typename T>
class QEnumerable : public QObject, public Enumerable<T>
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setGUI NOTIFY valueChanged)
    Q_PROPERTY(int max READ max CONSTANT)
    Q_PROPERTY(double valPerc READ valPerc NOTIFY valueChanged)

public:
    explicit QEnumerable(QObject *parent = nullptr) : QObject(parent), Enumerable<T>() { }
    explicit QEnumerable(const T& value, QObject *parent = nullptr) : QObject(parent), Enumerable<T>(value) { }
    virtual ~QEnumerable() { }

    // Setters
    void setValue(T val);

signals:
    // Informs other objects that the value had changed
    void valueChanged(T value);

public slots:
    // From GUI
    void plus(int n = 1) { changeRequest(QEnumerable<T>::nextValue(n)); }
    void minus(int n = 1) { changeRequest(QEnumerable<T>::prevValue(n)); }
    void setGUI(T val) { changeRequest(valueIfSet(val)); }

    // Helpers
    virtual void changeRequest(T val) { setValue(val); }
};

#endif // QENUMERABLE_H
