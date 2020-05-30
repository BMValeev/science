#ifndef SPLINECURVE_H
#define SPLINECURVE_H

#include "basecurve.h"
#include "spline.h"

class SplineCurve : public BaseCurve
{
    Q_OBJECT

public:
    SplineCurve(QObject *parent = nullptr);

    // Evaluators
    virtual QPointF evaluate(qreal x) const;
    virtual QPointF evaluate(QPointF p) const;
    virtual QVector<QPointF> evaluate(QVector<qreal>& xs) const;
    virtual QVector<QPointF> evaluate(QList<qreal>& xs) const;
    virtual QVector<QPointF> evaluate(qreal min, qreal max, int n) const;

signals:
    void interpolantChanged(Spline* interpolant);

private slots:
    void updateInterpolant(QVector<QPointF>& ps);

private:
    Spline mInterpolant;
};
Q_DECLARE_METATYPE(Spline*)

#endif // SPLINECURVE_H
