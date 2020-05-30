#include "basecurve.h"
#include <QPointF>
#include <QDebug>

BaseCurve::BaseCurve(QObject *parent)
    : QObject(parent)
    , mAllowRearrange(false)
{
    qRegisterMetaType<QVector<QPointF>>();
    qRegisterMetaType<QList<QPointF>>();
    qRegisterMetaType<const BaseCurve*>();
}

BaseCurve::~BaseCurve() { }

void BaseCurve::addPoint(QPointF p)
{
    // Insert new point at appropriate place
    QVector<QPointF>::iterator it = std::upper_bound(mPoints.begin(), mPoints.end(), p, comparePoints);
    insertPoint(it, p);
}

void BaseCurve::addPoint(QList<QPointF> &ps)
{
    // Trigger model reset
    pointsPreUpdateModel(mPoints);
    for(auto& p: ps) mPoints.append(p);
    sortPoints(mPoints);
    pointsPostUpdateModel();
    emit pointsChanged(mPoints);

    // Update maximum and minimum values
    for(auto& p: ps) {
        updateMax(p.x(), p.y());
        updateMin(p.x(), p.y());
    }
}

void BaseCurve::addPoint(QVector<QPointF> &ps)
{
    // Trigger model reset
    pointsPreUpdateModel(mPoints);
    mPoints.append(ps);
    sortPoints(mPoints);
    pointsPostUpdateModel();
    emit pointsChanged(mPoints);

    // Update maximum and minimum values
    for(auto& p: ps) {
        updateMax(p.x(), p.y());
        updateMin(p.x(), p.y());
    }
}

void BaseCurve::modifyPoint(int index, QPointF newP)
{
    if (index < 0 || index > mPoints.size() - 1)
        return;

    bool isOnLeftEdge = index == 0;
    bool isOnRightEdge = index == mPoints.size() - 1;

    QPointF oldP = mPoints[index];
    QPointF nextP = mPoints[qMax(0, index - 1)];
    QPointF prevP = mPoints[qMin(mPoints.size() - 1, index + 1)];

    qreal xNew = newP.x();
    qreal xPrev = prevP.x();
    qreal xNext = nextP.x();

    if (!isOnLeftEdge && qFuzzyCompare(xNew, xNext)) {
        qWarning() << "BaseCurve ====> can't set two points with too close x values: xPrev=" << xPrev << ", xNew=" << xNew << ", xNext=" << xNext;
        newP = oldP;
    }

    if (!isOnRightEdge && qFuzzyCompare(xNew, xPrev)) {
        qWarning() << "BaseCurve ====> can't set two points with too close x values: xPrev=" << xPrev << ", xNew=" << xNew << ", xNext=" << xNext;
        newP = oldP;
    }

    if (xNew <= xPrev || xNew >= xNext) // need to reset model
    {
        if (!mAllowRearrange)
            return;

        pointsPreUpdateModel(mPoints);
        mPoints[index] = newP;
        sortPoints(mPoints);
        pointsPostUpdateModel();
        pointsChanged(mPoints);
        return;
    }

    // Only modify existing value
    mPoints[index] = newP;
    pointChanged(index);
    pointsChanged(mPoints);
}

void BaseCurve::removePoint(QPointF p)
{
    if (mPoints.contains(p))
        removePoint(mPoints.indexOf(p));
}

void BaseCurve::removePoint(int index)
{
    if (index < 0 || index > mPoints.size() - 1)
        return;

    emit pointPreRemoved(index);
    mPoints.remove(index);
    emit pointPostRemoved();
    emit pointsChanged(mPoints);

    // Update maximum and minimum values
    updateMaxMinIter();
}

void BaseCurve::setAllowRearrange(bool allowRearrange)
{
    if (mAllowRearrange == allowRearrange)
        return;

    mAllowRearrange = allowRearrange;
    emit allowRearrangeChanged(mAllowRearrange);
}

void BaseCurve::insertPoint(QVector<QPointF>::iterator it, QPointF p)
{
    emit pointPreInserted(static_cast<int>(it - mPoints.begin()));
    mPoints.insert(it, p);
    emit pointPostInserted();
    emit pointsChanged(mPoints);

    // Update maximum and minimum values
    updateMax(p.x(), p.y());
    updateMin(p.x(), p.y());
}

void BaseCurve::updateMax(qreal x, qreal y)
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

void BaseCurve::updateMin(qreal x, qreal y)
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
void BaseCurve::updateMaxMinIter()
{
    mMax = QPointF(-MY_INF, -MY_INF);
    mMin = QPointF(MY_INF, MY_INF);

    for(auto& p: mPoints)
    {
        updateMax(p.x(), p.y());
        updateMin(p.x(), p.y());
    }
}

void BaseCurve::sortPoints(QVector<QPointF>& ps)
{
    std::sort(ps.begin(), ps.end(), comparePoints);
}

// sorting
// std::sort(pointsList.begin(), pointsList.end(), compare);
bool BaseCurve::comparePoints(const QPointF &first, const QPointF &second)
{
    if (first.x() < second.x())
    {
        return true;
    }
    else if (first.x() > second.x())
    {
        return false;
    }
    else
    {
        if (first.y() < second.y())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}
