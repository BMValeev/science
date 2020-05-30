#ifndef CIRCULARQVECTOR_H
#define CIRCULARQVECTOR_H

#include <QVector>

template<typename T>
class CircularQVector : private QVector<T>
{
public:
    // From QVector

    CircularQVector()
        : QVector<T>(0)
        , mCapacity(0)
        , mFirstIndex(0)
        , mLastIndex(-1)
    {
        this->reserve(0);
    }

    CircularQVector(int capacity)
        : QVector<T>(capacity)
        , mCapacity(capacity)
        , mFirstIndex(0)
        , mLastIndex(-1)
    {
        Q_ASSERT(capacity >= 0);
        this->reserve(mCapacity);
    }

    CircularQVector(int capacity, const T& value)
        : QVector<T>(capacity,value)
        , mCapacity(capacity)
        , mFirstIndex(0)
        , mLastIndex(capacity-1)
    {
        Q_ASSERT(capacity >= 0);
        this->reserve(mCapacity);
    }

    CircularQVector(int capacity, int size, const T& value)
        : QVector<T>(capacity,value)
        , mCapacity(capacity)
        , mFirstIndex(0)
        , mLastIndex(size-1)
    {
        Q_ASSERT(capacity >= 0);
        Q_ASSERT(size >= 0);
        this->reserve(mCapacity);
    }

    CircularQVector(std::initializer_list<T> list)
        : QVector<T>(list)
        , mCapacity(list.size())
        , mFirstIndex(0)
        , mLastIndex(list.size()-1)
    {
        this->resize(mCapacity);
        this->reserve(mCapacity);
    }

    CircularQVector(const CircularQVector<T> & other)
        : QVector<T>(other)
        , mCapacity(other.mCapacity)
        , mFirstIndex(other.mFirstIndex)
        , mLastIndex(other.mLastIndex)
    {
        this->reserve(mCapacity);
    }

    //~CircularQVector() { }
    T &at(int i)
    {
        Q_ASSERT(i >= 0);
        Q_ASSERT(i < mCapacity);
        return QVector<T>::at((mFirstIndex + i) % mCapacity);
    }

    T &operator[](int i)
    {
        Q_ASSERT(i >= 0);
        Q_ASSERT(i < mCapacity);
        return QVector<T>::operator[]((mFirstIndex + i) % mCapacity);
    }

    int size() const
    {
        if (mLastIndex == -1 && mFirstIndex == 0)
            return 0;
        else if (mLastIndex >= mFirstIndex) {
                Q_ASSERT(mLastIndex - mFirstIndex + 1 >= 0);
                return mLastIndex - mFirstIndex + 1;
             } else {
                Q_ASSERT((mCapacity - mFirstIndex) + mLastIndex + 1 >= 0);
                return (mCapacity - mFirstIndex) + mLastIndex + 1;
             }
    }

    bool isFull() const
    {
        return size() == capacity();
    }

    bool isLinearised() const
    {
        return mFirstIndex < mLastIndex;
    }

    /* does not working! error has to be corrected first, see test
    void linearize()
    {
        if (isLinearised())
            return;
        else {
            QVector<T> two = this->mid(0,mLastIndex+1);
            QVector<T> one = this->mid(mFirstIndex,mCapacity - mFirstIndex);
            // Copy the first half
            int i = 0;
            for (; i < one.size(); i++)
                QVector<T>::operator[](i) = one[i];
            // Copy the second half
            for (; i < one.size() + two.size(); i++)
                QVector<T>::operator[](i) = two[i];
            mFirstIndex = 0;
            mLastIndex = i - 1;
        }
    }*/

    QVector<T> toVector()
    {
        int size = this->size();
        QVector<T> result; result.reserve(size);

        if (isLinearised())
            result = this->mid(mFirstIndex,size);
        else {
            result.append(this->mid(mFirstIndex,mCapacity - mFirstIndex));
            result.append(this->mid(0,mLastIndex+1));
        }
        return result;
    }

    void append(const T &value)
    {
        if (mCapacity == 0)
            return;

        if (isFull())
            mFirstIndex = (mFirstIndex + 1) % mCapacity;
        mLastIndex = (mLastIndex + 1) % mCapacity;
        QVector<T>::operator[](mLastIndex) = value;
    }

    int capacity() const
    {
        return mCapacity;
    }

    bool isEmpty() const
    {
        return size() == 0;
    }

    const T &last()
    {
        Q_ASSERT(!isEmpty());
        return QVector<T>::operator[](mLastIndex);
    }

    const T &first()
    {
        Q_ASSERT(!isEmpty());
        return QVector<T>::operator[](mFirstIndex);
    }

    void setCapacity(int capacity)
    {
        Q_ASSERT(capacity >= 0);
        mCapacity = capacity;
        mFirstIndex = qMin(mFirstIndex, mCapacity-1);
        mLastIndex = qMin(mLastIndex, mCapacity-1);
        this->resize(mCapacity);
    }

private:
    int mCapacity = 0;
    int mFirstIndex = 0;
    int mLastIndex = -1;

};

#endif // CIRCULARQVECTOR_H
