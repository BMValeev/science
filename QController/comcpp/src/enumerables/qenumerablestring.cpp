#include "qenumerablestring.h"

void QEnumerableString::setValue(QString val)
{
    if (val == QEnumerableString::value())
        return;

    if (!values().contains(val)) {
        qWarning() << "QEnumerableString --> value is not in scale";
    }
    this->set(val);
    emit valueChanged(this->value());
}
