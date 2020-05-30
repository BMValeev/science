#ifndef PERSISTENT_H
#define PERSISTENT_H

#include <QSettings>

class Persistent
{
public:
    Persistent() { }
    virtual ~Persistent();

    virtual void loadData(QSettings& settings) = 0;
    virtual void saveData(QSettings& settings) const = 0;

};

#endif // PERSISTENT_H
