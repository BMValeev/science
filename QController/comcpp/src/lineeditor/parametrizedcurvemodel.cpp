#include "parametrizedcurvemodel.h"
#include "basecurve.h"
#include <QtConcurrent/QtConcurrent>
#include <QFutureWatcher>

ParametrizedCurveModel::ParametrizedCurveModel(QObject *parent)
    : BaseCurveModel(parent)
    , mFrom(0)
    , mTo(1)
    , mNPoints(100)
    , mUpdating(false)
{
    connect(this, &ParametrizedCurveModel::fromChanged, this, &ParametrizedCurveModel::pointsEvaluateStart);
    connect(this, &ParametrizedCurveModel::toChanged, this, &ParametrizedCurveModel::pointsEvaluateStart);
    connect(this, &ParametrizedCurveModel::nPointsChanged, this, &ParametrizedCurveModel::pointsEvaluateStart);
    connect(this, &ParametrizedCurveModel::curveChanged, this, &ParametrizedCurveModel::pointsEvaluateStart);
    connect(&mEvaluationWatcher, &QFutureWatcher<void>::finished, this, &ParametrizedCurveModel::pointsEvaluateFinished);
}

Qt::ItemFlags ParametrizedCurveModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::NoItemFlags;
}

int ParametrizedCurveModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mCurve)
        return 0;

    return mPoints.size();
}

QVariant ParametrizedCurveModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mCurve)
        return QVariant();

    switch (role)
    {
    case PointRole:
        return QVariant::fromValue(mPoints[index.row()]);
    case XRole:
        return QVariant::fromValue(mPoints[index.row()].x());
    case YRole:
        return QVariant::fromValue(mPoints[index.row()].y());
    }
    return QVariant();
}

void ParametrizedCurveModel::pointsEvaluateStart()
{
    if (!mCurve) {
        return;
    }

    beginResetModel();
    setUpdating(true);

    mEvaluationWatcher.setFuture(QtConcurrent::run(this, &ParametrizedCurveModel::evaluate));
}

void ParametrizedCurveModel::evaluate()
{
    mPoints = mCurve->evaluate(mFrom, mTo, mNPoints);
    updateSeries(mPoints);
    updateMaxMinIter();
}

void ParametrizedCurveModel::pointsEvaluateFinished()
{
    endResetModel();
    setUpdating(false);
}

void ParametrizedCurveModel::setUpdating(bool updating)
{
    if (mUpdating == updating)
        return;

    mUpdating = updating;
    qWarning() << "Updating =" << mUpdating;
    emit updatingChanged(mUpdating);
}

void ParametrizedCurveModel::setFrom(qreal from)
{
    if (qFuzzyCompare(mFrom, from))
        return;

    mFrom = from;
    emit fromChanged(mFrom);
}

void ParametrizedCurveModel::setTo(qreal to)
{
    if (qFuzzyCompare(mTo, to))
        return;

    mTo = to;
    emit toChanged(mTo);
}

void ParametrizedCurveModel::setNPoints(int nPoints)
{
    if (mNPoints == nPoints)
        return;

    mNPoints = nPoints;
    emit nPointsChanged(mNPoints);
}

void ParametrizedCurveModel::setCurve(QObject *curveObject)
{
    if (!curveObject)
        return;

    BaseCurve* curve = qobject_cast<BaseCurve*>(curveObject);

    if (!curve)
        return;

    if (mCurve == curve)
        return;

    beginResetModel();

    if (mCurve)
        mCurve->disconnect(this);

    mCurve = curve;

    // Connections
    connect(mCurve, &BaseCurve::pointsChanged, this, [=]() {
        pointsEvaluateStart();
    });

    endResetModel();
    emit curveChanged(mCurve);
}

void ParametrizedCurveModel::updateMax(qreal x, qreal y)
{
    if (x > mMax.x() && y > mMax.y()) {
        mMax = QPointF(x, y);
        emit maxChanged(mMax);
    } else if (x > mMax.x()) {
        mMax.setX(x);
        emit maxChanged(mMax);
    } else if (y > mMax.y()) {
        mMax.setY(y);
        emit maxChanged(mMax);
    }
}

void ParametrizedCurveModel::updateMin(qreal x, qreal y)
{
    if (x < mMin.x() && y < mMin.y()) {
        mMin = QPointF(x, y);
        emit minChanged(mMin);
    } else if (x < mMin.x()) {
        mMin.setX(x);
        emit minChanged(mMin);
    } else if (y < mMin.y()) {
        mMin.setY(y);
        emit minChanged(mMin);
    }
}

#define MY_INF 100000000000000000000000000.0
void ParametrizedCurveModel::updateMaxMinIter()
{
    mMax = QPointF(-MY_INF, -MY_INF);
    mMin = QPointF(MY_INF, MY_INF);

    for(auto& p: mPoints)
    {
        updateMax(p.x(), p.y());
        updateMin(p.x(), p.y());
    }
}
