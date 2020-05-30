#ifndef ENUM_H
#define ENUM_H

#include <QVector>
#include "utils.h"

template<typename T>
class Enumerable
{
public:
    // Constructors
    Enumerable() : mIndex(0) { }
    Enumerable(const T& value) { mIndex = values().indexOf(valueIfSet(value)); }
    Enumerable(Enumerable<T> const &index) : mIndex(index.mIndex) { }
    virtual ~Enumerable() { }

    // Allowed values of the enumerable - override this virtual function
    virtual const QVector<T>& values() const {
        static const QVector<T> values = {T()};
        return values;
    }

    // Getters
    virtual T max() const { return values().last(); }
    virtual T min() const { return values().first(); }
    virtual double valPerc() const = 0;
    const T value() const { return values().at(mIndex); }
    const T& nextValue(int n = 1) const { return values().at(qMax(qMin(values().size()-1, mIndex + n),0)); }
    const T& prevValue(int n = 1) const { return values().at(qMax(qMin(values().size()-1, mIndex - n),0)); }
    const T& valueIfSet(const T& val) const
    {
        const QVector<T>& vals = values();
        if (vals.contains(val))
        {
            return val;
        }
        else
        {
            // Value is not found, iterate and search next one that is smaller
            for(int i=vals.size()-1; i >= 0; --i)
            {
                if (vals[i] < val) {
                    return vals[i];
                }
            }
            return vals[0];
        }
    }
    // Setter
    void set(const T& val)
    {
        mIndex = values().indexOf(valueIfSet(val));
    }
    void operator=(const T &v ) {
       set(v.value());
    }
    // Plus
    const T plus(int n = 1)
    {
        mIndex = qMax(qMin(values().size()-1, mIndex + n),0);
        return value();
    }
    T operator+=(const T &rhs) {
        // We just return sum of value and summand
        return value() + rhs;
    }
    const T operator+(const T &other) const {
        return this->value() + other;
    }
    // Minus
    const T minus(int n = 1)
    {
        mIndex = qMax(qMin(values().size()-1, mIndex - n),0);
        return value();
    }
    T operator-=(const T &rhs) {
        // We just return subtraction of value and summand
        return value() - rhs;
    }
    const T operator-(const T &other) const {
        return this->value() - other;
    }
    // Comparison
    bool operator==(const Enumerable<T> &other) const {
        return value() == other.value();
    }
    bool operator!=(const Enumerable<T> &other) const {
        return !(*this == other);
    }
    bool operator==(const T &other) const {
        return value() == other;
    }
    bool operator!=(const T &other) const {
        return !(*this == other);
    }
    bool operator<(const Enumerable<T> &other) const {
        return value() < other.value();
    }
    bool operator>=(const Enumerable<T> &other) const {
        return !(*this < other);
    }
    bool operator<(const int &other) const {
        return value() < other;
    }
    bool operator>=(const int &other) const {
        return !(*this < other);
    }
    bool operator>(const Enumerable<T> &other) const {
        return value() > other.value();
    }
    bool operator<=(const Enumerable<T> &other) const {
        return !(*this > other);
    }
    bool operator>(const int &other) const {
        return value() > other;
    }
    bool operator<=(const int &other) const {
        return !(*this > other);
    }

protected:
    int mIndex;
};

#endif // ENUM_H
