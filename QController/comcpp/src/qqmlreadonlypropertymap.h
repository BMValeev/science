#ifndef QQMLREADONLYPROPERTYMAP_H
#define QQMLREADONLYPROPERTYMAP_H

#include <QObject>
#include <QQmlPropertyMap>

class QQmlReadonlyPropertyMap : public QQmlPropertyMap
{
    Q_OBJECT

public:
    QQmlReadonlyPropertyMap(QObject* parent = nullptr);

    QVariant updateValue(const QString &key, const QVariant &input) override;
};

#endif // QQMLREADONLYPROPERTYMAP_H
