#include "qenumerable.h"

template<typename T>
void QEnumerable<T>::setValue(T val)
{
    if (val == QEnumerable<T>::value())
        return;

    if (!QEnumerable<T>::values().contains(val)) {
        qWarning() << "QEnumerable<T> --> value is not in power scale";
    }
    this->set(val);
    emit valueChanged(this->value());
}


