#include "basecurvemodel.h"
#include "basecurve.h"
#include <QDebug>

BaseCurveModel::BaseCurveModel(QObject *parent)
    : QAbstractListModel(parent)
    , mCurve(nullptr)
{
    connect(this, &BaseCurveModel::seriesAppended, this, [=](QXYSeries* series) {
        if (!mCurve)
            return;

        updateSeries(mCurve->points(), series);
    });
}

QObject *BaseCurveModel::curve() const { return mCurve; }

QQmlListProperty<QObject> BaseCurveModel::series()
{
    return QQmlListProperty<QObject>(this, this,
                                     &BaseCurveModel::appendSeries,
                                     &BaseCurveModel::seriesCount,
                                     &BaseCurveModel::series,
                                     &BaseCurveModel::clearSeries);
}

Qt::ItemFlags BaseCurveModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> BaseCurveModel::roleNames() const
{
    return QHash<int, QByteArray>({{PointRole, "point"}, {XRole, "xRole"}, {YRole, "yRole"}});
}

void BaseCurveModel::appendSeries(QObject *seriesObject)
{
    if (!seriesObject)
        return;

    QXYSeries* series = qobject_cast<QXYSeries*>(seriesObject);

    if (!series)
        return;

    if (mSeries.contains(series))
        return;

    mSeries.append(series);
    emit seriesAppended(series);
}

int BaseCurveModel::seriesCount() const
{
    return mSeries.size();
}

QObject *BaseCurveModel::series(int index) const
{
    return mSeries.at(index);
}

void BaseCurveModel::clearSeries()
{
    mSeries.clear();
}

void BaseCurveModel::updateSeries(const QVector<QPointF> &points)
{
    for (auto& series: mSeries) {
        updateSeries(points, series);
    }
}

void BaseCurveModel::updateSeries(const QVector<QPointF> &points, QXYSeries *series)
{
    if (!series)
        return;

    series->replace(points);
}

void BaseCurveModel::appendSeries(QQmlListProperty<QObject> *list, QObject *seriesObject)
{
    reinterpret_cast<BaseCurveModel*>(list->data)->appendSeries(seriesObject);
}

int BaseCurveModel::seriesCount(QQmlListProperty<QObject> *list)
{
    return reinterpret_cast<BaseCurveModel*>(list->data)->seriesCount();
}

QObject *BaseCurveModel::series(QQmlListProperty<QObject> *list, int index)
{
    return reinterpret_cast<BaseCurveModel*>(list->data)->series(index);
}

void BaseCurveModel::clearSeries(QQmlListProperty<QObject> *list)
{
    reinterpret_cast<BaseCurveModel*>(list->data)->clearSeries();
}
