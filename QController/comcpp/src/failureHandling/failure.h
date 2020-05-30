#ifndef FAILURE_H
#define FAILURE_H

#include <QObject>
#include <QTimer>
#include <QHash>

#define DEFAULT_FAILURE_ACTIVE_INTERVAL 3000

class Failure : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int code READ code CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
    Q_PROPERTY(int activeInterval READ activeInterval WRITE setActiveInterval NOTIFY activeIntervalChanged)

public:
    explicit Failure(const int code,
                     const QString description,
                     const int activeInterval = DEFAULT_FAILURE_ACTIVE_INTERVAL,
                     QObject *parent = nullptr);

    static void addFailure(Failure* f);

    // Getters
    int code() const { return mCode; }
    QString description() const { return mDescription; }
    bool active() const { return mActive; }
    int activeInterval() const { return mActiveInterval; }
    static Failure* failure(int code) { return mFailures.value(code); }
    static const QList<Failure *> failures();
    static const QList<QObject *> activeFailures();

signals:
    void activeChanged(bool active);
    void activeIntervalChanged(int activeInterval);

public slots:
    void setActive(bool active);
    void setActiveInterval(int activeInterval);

private:
    static QHash<int, Failure*> mFailures;
    const int mCode;
    const QString mDescription;
    int mActiveInterval;
    bool mActive;
    QTimer mActiveWatcher;
};

#endif // FAILURE_H
