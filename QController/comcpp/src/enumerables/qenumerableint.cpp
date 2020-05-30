#include "qenumerableint.h"

void QEnumerableInt::setValue(int val)
{
    if (val == value())
        return;

    if (!values().contains(val)) {
        qWarning() << "QEnumerableInt --> value is not in scale";
    }
    this->set(val);
    emit valueChanged(this->value());
}
