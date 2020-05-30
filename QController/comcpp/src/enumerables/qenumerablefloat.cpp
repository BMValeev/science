#include "qenumerablefloat.h"

void QEnumerableFloat::setValue(float val)
{
    if (qFuzzyCompare(val, value()))
        return;

    if (!values().contains(val)) {
        qWarning() << "QEnumerableFloat --> value is not in power scale";
    }
    this->set(val);
    emit valueChanged(this->value());
}
