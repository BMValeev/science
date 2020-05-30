#ifndef LINEFILE_H
#define LINEFILE_H

#include <QObject>
#include <QDateTime>
#include <QPointF>

#include "splinecurve.h"

class LineFile : public SplineCurve
{
    Q_OBJECT
    Q_PROPERTY(QString file READ file WRITE setFile NOTIFY fileChanged)
    Q_PROPERTY(QString lastSaveTime READ lastSaveTime NOTIFY lastSaveTimeChanged)
    Q_PROPERTY(bool synchronizeOnChange READ synchronizeOnChange WRITE setSynchronizeOnChange NOTIFY synchronizeOnChangeChanged)

public:
    explicit LineFile(QObject *parent = nullptr);
    ~LineFile();

    // Getters
    QString lastSaveTime() const { return mLastSaveTime.toString(mDateTimeFormat); }
    QString file() const { return mFile; }
    bool synchronizeOnChange() const { return mSynchronizeOnChange; }

signals:
    void lastSaveTimeChanged(QString lastSaveTime);
    void fileChanged(QString file);
    void synchronizeOnChangeChanged(bool synchronizeOnChange);

public slots:
    void setFile(QString file);
    void save();
    void setSynchronizeOnChange(bool synchronizeOnChange);

private slots:
    void load(QString path);
    void save(QString path);

private:
    static QString mDateTimeFormat;
    QString mFile;
    QDateTime mLastSaveTime;
    bool mSynchronizeOnChange;

    // Helpers
    static bool checkPath(QString path);
};

#endif // LINEFILE_H
