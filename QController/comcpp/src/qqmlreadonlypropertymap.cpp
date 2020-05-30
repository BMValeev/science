#include "qqmlreadonlypropertymap.h"

QQmlReadonlyPropertyMap::QQmlReadonlyPropertyMap(QObject *parent)
    : QQmlPropertyMap(this, parent)
{ }

QVariant QQmlReadonlyPropertyMap::updateValue(const QString &key, const QVariant &input)
{
    // Prevent updates from QML
    Q_UNUSED(input)
    return value(key);
}
