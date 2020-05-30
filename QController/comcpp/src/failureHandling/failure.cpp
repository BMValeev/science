#include "failure.h"

QHash<int, Failure*> Failure::mFailures = {};

Failure::Failure(const int code,
                 const QString description,
                 const int activeInterval,
                 QObject *parent)
    : QObject(parent)
    , mCode(code)
    , mDescription(description)
    , mActiveInterval(activeInterval)
    , mActive(false)
    , mActiveWatcher(this)
{
    // Setup watcher
    mActiveWatcher.setSingleShot(true);
    connect(&mActiveWatcher, &QTimer::timeout, this, [=]() {
        setActive(false);
    });
    if (mActiveInterval > 0) {
        mActiveWatcher.setInterval(mActiveInterval);
    }
    connect(this, &Failure::activeIntervalChanged, this, [=](int interval) {
        if (interval > 0) {
            mActiveWatcher.setInterval(interval);
        }
    });
}

void Failure::addFailure(Failure *f)
{
    if (!f)
        return;

    if (!mFailures.contains(f->code())) {
        mFailures.insert(f->code(), f);
    }
}

const QList<Failure *> Failure::failures()
{
    QList<Failure*> l;
    for (auto& f: mFailures) l.append(f);
    return l;
}

const QList<QObject*> Failure::activeFailures()
{
    QList<QObject*> l;
    for (auto& f: mFailures) {
        if (f->active()) l.append(f);
    }
    return l;
}

void Failure::setActive(bool active)
{
    if (mActive == active) {
        if (active && mActiveInterval > 0) mActiveWatcher.start(); // should restart the watcher
        return;
    }

    mActive = active;

    if (mActive) {
        if (mActiveInterval > 0) mActiveWatcher.start();
    } else {
        mActiveWatcher.stop();
    }

    emit activeChanged(mActive);
}

void Failure::setActiveInterval(int activeInterval)
{
    if (mActiveInterval == activeInterval)
        return;

    mActiveInterval = activeInterval;
    emit activeIntervalChanged(mActiveInterval);
}
