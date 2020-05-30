#ifndef BASECURVEMODEL_H
#define BASECURVEMODEL_H

#include <QAbstractListModel>
#include <QQmlListProperty>
#include <QtCharts>

class BaseCurve;

class BaseCurveModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QObject* curve READ curve WRITE setCurve NOTIFY curveChanged)
    Q_PROPERTY(QQmlListProperty<QObject> series READ series)

public:
    explicit BaseCurveModel(QObject *parent = nullptr);

    // Getters
    QObject* curve() const;
    QQmlListProperty<QObject> series();

    // Basic functionality:
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    enum { PointRole = Qt::UserRole, XRole, YRole };
    QHash<int, QByteArray> roleNames() const override;

    // For series list
    void appendSeries(QObject* seriesObject);
    int seriesCount() const;
    QObject* series(int index) const;
    void clearSeries();

public slots:
    virtual void setCurve(QObject* curve) { Q_UNUSED(curve); }
    void updateSeries(const QVector<QPointF>& points);
    void updateSeries(const QVector<QPointF>& points, QXYSeries* series);

signals:
    void curveChanged(QObject* curve);
    void seriesAppended(QXYSeries* series);

protected:
    BaseCurve* mCurve;
    QVector<QXYSeries*> mSeries;

    // For series list
    static void appendSeries(QQmlListProperty<QObject>* list, QObject* seriesObject);
    static int seriesCount(QQmlListProperty<QObject>* list);
    static QObject* series(QQmlListProperty<QObject>* list, int index);
    static void clearSeries(QQmlListProperty<QObject>* list);

};

#endif // BASECURVEMODEL_H
