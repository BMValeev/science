#ifndef CURVEBASE_H
#define CURVEBASE_H

#include <QObject>
#include <QVector>
#include <QPointF>

class BaseCurve : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPointF max READ max NOTIFY maxChanged)
    Q_PROPERTY(QPointF min READ min NOTIFY minChanged)
    Q_PROPERTY(bool allowRearrange READ allowRearrange WRITE setAllowRearrange NOTIFY allowRearrangeChanged)

public:
    explicit BaseCurve(QObject *parent = nullptr);
    virtual ~BaseCurve();

    // Getters
    QPointF max() const { return mMax; }
    QPointF min() const { return mMin; }
    bool allowRearrange() const { return mAllowRearrange; }
    Q_INVOKABLE QPointF point(int index) const { return mPoints.value(index); }
    const QVector<QPointF>& points() const { return mPoints; }
    Q_INVOKABLE int size() const { return mPoints.size(); }

    // Evaluators
    virtual QPointF evaluate(qreal x) const = 0;
    virtual QPointF evaluate(QPointF p) const = 0;
    virtual QVector<QPointF> evaluate(QVector<qreal>& xs) const = 0;
    virtual QVector<QPointF> evaluate(QList<qreal>& xs) const = 0;
    virtual QVector<QPointF> evaluate(qreal min, qreal max, int n) const = 0;

    // Helpers
    static bool comparePoints(const QPointF& first, const QPointF& second);
    static void sortPoints(QVector<QPointF> &ps);

signals:
    void maxChanged(QPointF max);
    void minChanged(QPointF min);
    void allowRearrangeChanged(bool allowRearrange);
    void pointsChanged(QVector<QPointF>& points); // emitted whenever any point(s) change
    // Signals for model
    void pointChanged(int index);
    void pointsPreUpdateModel(QVector<QPointF>& points); // emitted before resetting model
    void pointsPostUpdateModel(); // emitted after resetting model
    void pointPreInserted(int index);
    void pointPostInserted();
    void pointPreRemoved(int index);
    void pointPostRemoved();

public slots:
    void setAllowRearrange(bool allowRearrange);
    // Data modifiers
    void addPoint(QPointF p);
    void addPoint(QList<QPointF>& ps);
    void addPoint(QVector<QPointF>& ps);
    void modifyPoint(int index, QPointF newP);
    void removePoint(QPointF p);
    void removePoint(int index);


private:
    QVector<QPointF> mPoints;
    QPointF mMax;
    QPointF mMin;
    bool mAllowRearrange;

    // Helpers
    void updateMax(qreal x, qreal y);
    void updateMin(qreal x, qreal y);
    void updateMaxMinIter();
    void insertPoint(QVector<QPointF>::iterator it, QPointF p);
};
Q_DECLARE_METATYPE(QVector<QPointF>);
Q_DECLARE_METATYPE(QVector<QPointF>*);
Q_DECLARE_METATYPE(QList<QPointF>);
Q_DECLARE_METATYPE(QList<QPointF>*);
Q_DECLARE_METATYPE(const BaseCurve*);

#endif // CURVEBASE_H
