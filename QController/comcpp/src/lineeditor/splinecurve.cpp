#include "splinecurve.h"
#include <QDebug>
#include <QThread>

SplineCurve::SplineCurve(QObject *parent)
    : BaseCurve(parent)
{
    qRegisterMetaType<Spline*>();

    connect(this, &BaseCurve::pointsChanged, this, &SplineCurve::updateInterpolant);
}

QPointF SplineCurve::evaluate(qreal x) const
{
    return QPointF(x, mInterpolant(x));
}

QPointF SplineCurve::evaluate(QPointF p) const
{
    return evaluate(p.x());
}

QVector<QPointF> SplineCurve::evaluate(QVector<qreal> &xs) const
{
    QVector<qreal> xss(xs);
    std::sort(xss.begin(), xss.end());
    QVector<QPointF> ps;
    ps.reserve(xs.size());

    for(int i = 0; i < xss.size(); i++) {
        ps.append(evaluate(xss[i]));
    }

    return ps;
}

QVector<QPointF> SplineCurve::evaluate(QList<qreal> &xs) const
{
    QList<qreal> xss(xs);
    std::sort(xss.begin(), xss.end());
    QVector<QPointF> ps;
    ps.reserve(xs.size());

    for(int i = 0; i < xss.size(); i++) {
        ps.append(evaluate(xss[i]));
    }
    return ps;
}

QVector<QPointF> SplineCurve::evaluate(qreal min, qreal max, int n) const
{
    qWarning() << "Evaluating points, min=" << min << ", max=" << max << ", n=" << n << QThread::currentThread();
    QVector<QPointF> ps(n);

    qreal x = min;
    qreal step = (max - min) / qMax((n - 1), 1);
    for (int i=0; i < n; i++) {
        ps[i] = evaluate(x);
        x += step;
    }

    return ps;
}

void SplineCurve::updateInterpolant(QVector<QPointF> &ps)
{
    if (ps.size() < 3)
        return;

    // First extract all points
    uint32_t size = static_cast<uint32_t>(ps.size());
    std::vector<qreal> xs(size);
    std::vector<qreal> ys(size);

    for(uint64_t i=0; i < size; i++) {
        xs[i] = ps[static_cast<int>(i)].x();
        ys[i] = ps[static_cast<int>(i)].y();
    }

    mInterpolant.setPoints(xs, ys);
    emit interpolantChanged(&mInterpolant);
}
