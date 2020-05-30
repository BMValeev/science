#ifndef PARAMETRIZEDCURVEMODEL_H
#define PARAMETRIZEDCURVEMODEL_H

#include "basecurvemodel.h"

class ParametrizedCurveModel : public BaseCurveModel
{
    Q_OBJECT
    Q_PROPERTY(qreal from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(qreal to READ to WRITE setTo NOTIFY toChanged)
    Q_PROPERTY(int nPoints READ nPoints WRITE setNPoints NOTIFY nPointsChanged)
    Q_PROPERTY(bool updating READ updating NOTIFY updatingChanged)
    Q_PROPERTY(QPointF max READ max NOTIFY maxChanged)
    Q_PROPERTY(QPointF min READ min NOTIFY minChanged)

public:
    ParametrizedCurveModel(QObject *parent = nullptr);

    // Getters
    QPointF max() const { return mMax; }
    QPointF min() const { return mMin; }
    qreal from() const { return mFrom; }
    qreal to() const { return mTo; }
    int nPoints() const { return mNPoints; }
    bool updating() const { return mUpdating; }

    // Basic functionality:
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


public slots:
    // Properties
    void setCurve(QObject *curveObject) override;
    void setFrom(qreal from);
    void setTo(qreal to);
    void setNPoints(int nPoints);
    void setUpdating(bool updating);
    // Other
    void pointsEvaluateStart();
    void pointsEvaluateFinished();

signals:
    void fromChanged(qreal from);
    void toChanged(qreal to);
    void nPointsChanged(int nPoints);
    void maxChanged(QPointF max);
    void minChanged(QPointF min);
    void updatingChanged(bool updating);

private:
    QFutureWatcher<void> mEvaluationWatcher;
    QVector<QPointF> mPoints;
    QPointF mMax;
    QPointF mMin;
    qreal mFrom;
    qreal mTo;
    int mNPoints;
    bool mUpdating;

    // Helpers
    void updateMax(qreal x, qreal y);
    void updateMin(qreal x, qreal y);
    void updateMaxMinIter();
    void evaluate();
};

#endif // PARAMETRIZEDCURVEMODEL_H
