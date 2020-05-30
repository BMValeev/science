#include "linefile.h"
#include <QSettings>
#include <QFileInfo>

QString LineFile::mDateTimeFormat = "dd MMM, yyyy - hh:mm:ss.zzz";

LineFile::LineFile(QObject *parent)
    : SplineCurve(parent)
    , mLastSaveTime(QDateTime())
    , mSynchronizeOnChange(false)
{
    connect(this, &LineFile::fileChanged, this, &LineFile::load);
    connect(this, &LineFile::synchronizeOnChangeChanged, this, [=](bool synchronizeOnChange) {
        static QMetaObject::Connection conn;

        if (synchronizeOnChange) {
            conn = connect(this, &BaseCurve::pointsChanged, this, QOverload<>::of(&LineFile::save));
        } else {
            if (conn)
                disconnect(conn);
        }
    });

    setFile("");
}

LineFile::~LineFile()
{
    save(mFile);
}

void LineFile::setFile(QString file)
{
    if (mFile == file)
        return;

    mFile = file;
    emit fileChanged(mFile);
}

bool LineFile::checkPath(QString path)
{
    QFileInfo fi(path);

    if (!fi.exists() || !fi.isFile())
        return false;

    // Check access rights
    if (!fi.isWritable()) {
        // Add rights to write
        if (!QFile::setPermissions(path, QFileDevice::WriteOwner | QFileDevice::ReadOwner )) {
            qWarning( "failed to set the write permissions to configuration file" );
            return false;
        }
    }

    return true;
}

void LineFile::load(QString path)
{
    if (!checkPath(path))
        return;

    QSettings settings(path, QSettings::IniFormat); settings.setIniCodec("UTF-8");

    // Get last save time
    mLastSaveTime = QDateTime::fromString(settings.value("lastSaveTime", "").toString(), mDateTimeFormat);
    emit lastSaveTimeChanged(mLastSaveTime.toString(mDateTimeFormat));

    // Read data points
    int np = settings.beginReadArray("points");
    QVector<QPointF> v(np);
    for (int i = 0; i < np; i++)
    {
        settings.setArrayIndex(i);
        v[i] = QPointF(settings.value("x", static_cast<float>(i)).toReal(),
                       settings.value("y", 0.0).toReal());
    }
    settings.endArray();
    addPoint(v);
}

void LineFile::save()
{
    save(mFile);
}

void LineFile::setSynchronizeOnChange(bool synchronizeOnChange)
{
    if (mSynchronizeOnChange == synchronizeOnChange)
        return;

    mSynchronizeOnChange = synchronizeOnChange;
    emit synchronizeOnChangeChanged(mSynchronizeOnChange);
}

void LineFile::save(QString path)
{
    if (!checkPath(path))
        return;

    QSettings settings(path, QSettings::IniFormat); settings.setIniCodec("UTF-8");

    // Clear file
    settings.clear();

    // Set last save time
    mLastSaveTime = QDateTime::currentDateTime();
    settings.setValue("lastSaveTime", mLastSaveTime.toString(mDateTimeFormat));
    emit lastSaveTimeChanged(mLastSaveTime.toString(mDateTimeFormat));

    // Write data points
    settings.beginWriteArray("points");
    for (int i = 0; i < size(); i++)
    {
        settings.setArrayIndex(i);
        settings.setValue("x", QVariant(point(i).x()));
        settings.setValue("y", QVariant(point(i).y()));
    }
    settings.endArray();
    settings.sync();
}
