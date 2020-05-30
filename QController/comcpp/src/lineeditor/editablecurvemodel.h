#ifndef CURVEMODEL_H
#define CURVEMODEL_H

#include "basecurvemodel.h"

class EditableCurveModel : public BaseCurveModel
{
    Q_OBJECT

public:
    explicit EditableCurveModel(QObject *parent = nullptr)
        : BaseCurveModel(parent)
    { }

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

public slots:
    void setCurve(QObject *curve) override;

signals:

private:

};

#endif // CURVEMODEL_H
