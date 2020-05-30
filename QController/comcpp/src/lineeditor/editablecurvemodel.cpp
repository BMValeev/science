#include "editablecurvemodel.h"
#include "basecurve.h"
#include <QDebug>

int EditableCurveModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mCurve)
        return 0;

    return mCurve->size();
}

QVariant EditableCurveModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mCurve)
        return QVariant();

    switch (role)
    {
    case PointRole:
        return QVariant::fromValue(mCurve->point(index.row()));
    case XRole:
        return QVariant::fromValue(mCurve->point(index.row()).x());
    case YRole:
        return QVariant::fromValue(mCurve->point(index.row()).y());
    }
    return QVariant();
}

bool EditableCurveModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mCurve)
        return false;

    if (data(index, role) != value) {
        int i = index.row();
        QPointF p = mCurve->point(i);
        bool ok;

        switch (role)
        {
        case PointRole:
            if (value.canConvert(QMetaType::QPointF))
            {
                mCurve->modifyPoint(i, value.toPointF());
                return true;
            } else {
                qWarning() << "CurveModel ===> point role should be convertable to QPointF";
                return false;
            }
        case XRole: {
            qreal xNew = value.toReal(&ok);
            if (ok) {
                p.setX(xNew);
                mCurve->modifyPoint(i, p);
                return true;
            } else {
                qWarning() << "CurveModel ===> x role should be convertable to qreal";
                return false;
            }
        }
        case YRole:{
            qreal yNew = value.toReal(&ok);
            if (ok) {
                p.setY(yNew);
                mCurve->modifyPoint(i, p);
                return true;
            } else {
                qWarning() << "CurveModel ===> y role should be convertable to qreal";
                return false;
            }
        }
        }
    }
    return false;
}

void EditableCurveModel::setCurve(QObject *curveObject)
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
    connect(mCurve, &BaseCurve::pointChanged, this, [=](int index){
        dataChanged(QAbstractItemModel::createIndex(index, 0), QAbstractItemModel::createIndex(index,0));
    });
    connect(mCurve, &BaseCurve::pointsPreUpdateModel, this, [=](QVector<QPointF>& points) {
        Q_UNUSED(points);
        beginResetModel();
    });
    connect(mCurve, &BaseCurve::pointsPostUpdateModel, this, [=]() {
        endResetModel();
    });
    connect(mCurve, &BaseCurve::pointPreInserted, this, [=](int index) {
        beginInsertRows(QModelIndex(), index, index);
    });
    connect(mCurve, &BaseCurve::pointPostInserted, this, [=]() {
        endInsertRows();
    });
    connect(mCurve, &BaseCurve::pointPreRemoved, this, [=](int index) {
        beginRemoveRows(QModelIndex(), index, index);
    });
    connect(mCurve, &BaseCurve::pointPostRemoved, this, [=]() {
        endRemoveRows();
    });
    connect(mCurve, &BaseCurve::pointsChanged, this, [=](QVector<QPointF>& points) {
        updateSeries(points);
    });

    endResetModel();
    emit curveChanged(mCurve);
}
