/****************************************************************************
** Meta object code from reading C++ file 'parametrizedcurvemodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../QController/comcpp/src/lineeditor/parametrizedcurvemodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parametrizedcurvemodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ParametrizedCurveModel_t {
    QByteArrayData data[22];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParametrizedCurveModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParametrizedCurveModel_t qt_meta_stringdata_ParametrizedCurveModel = {
    {
QT_MOC_LITERAL(0, 0, 22), // "ParametrizedCurveModel"
QT_MOC_LITERAL(1, 23, 11), // "fromChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "from"
QT_MOC_LITERAL(4, 41, 9), // "toChanged"
QT_MOC_LITERAL(5, 51, 2), // "to"
QT_MOC_LITERAL(6, 54, 14), // "nPointsChanged"
QT_MOC_LITERAL(7, 69, 7), // "nPoints"
QT_MOC_LITERAL(8, 77, 10), // "maxChanged"
QT_MOC_LITERAL(9, 88, 3), // "max"
QT_MOC_LITERAL(10, 92, 10), // "minChanged"
QT_MOC_LITERAL(11, 103, 3), // "min"
QT_MOC_LITERAL(12, 107, 15), // "updatingChanged"
QT_MOC_LITERAL(13, 123, 8), // "updating"
QT_MOC_LITERAL(14, 132, 8), // "setCurve"
QT_MOC_LITERAL(15, 141, 11), // "curveObject"
QT_MOC_LITERAL(16, 153, 7), // "setFrom"
QT_MOC_LITERAL(17, 161, 5), // "setTo"
QT_MOC_LITERAL(18, 167, 10), // "setNPoints"
QT_MOC_LITERAL(19, 178, 11), // "setUpdating"
QT_MOC_LITERAL(20, 190, 19), // "pointsEvaluateStart"
QT_MOC_LITERAL(21, 210, 22) // "pointsEvaluateFinished"

    },
    "ParametrizedCurveModel\0fromChanged\0\0"
    "from\0toChanged\0to\0nPointsChanged\0"
    "nPoints\0maxChanged\0max\0minChanged\0min\0"
    "updatingChanged\0updating\0setCurve\0"
    "curveObject\0setFrom\0setTo\0setNPoints\0"
    "setUpdating\0pointsEvaluateStart\0"
    "pointsEvaluateFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParametrizedCurveModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       6,  114, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       6,    1,   85,    2, 0x06 /* Public */,
       8,    1,   88,    2, 0x06 /* Public */,
      10,    1,   91,    2, 0x06 /* Public */,
      12,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   97,    2, 0x0a /* Public */,
      16,    1,  100,    2, 0x0a /* Public */,
      17,    1,  103,    2, 0x0a /* Public */,
      18,    1,  106,    2, 0x0a /* Public */,
      19,    1,  109,    2, 0x0a /* Public */,
      20,    0,  112,    2, 0x0a /* Public */,
      21,    0,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void, QMetaType::QReal,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QPointF,    9,
    QMetaType::Void, QMetaType::QPointF,   11,
    QMetaType::Void, QMetaType::Bool,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::QObjectStar,   15,
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void, QMetaType::QReal,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::QReal, 0x00495103,
       5, QMetaType::QReal, 0x00495103,
       7, QMetaType::Int, 0x00495103,
      13, QMetaType::Bool, 0x00495001,
       9, QMetaType::QPointF, 0x00495001,
      11, QMetaType::QPointF, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       5,
       3,
       4,

       0        // eod
};

void ParametrizedCurveModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ParametrizedCurveModel *_t = static_cast<ParametrizedCurveModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fromChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 1: _t->toChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: _t->nPointsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->maxChanged((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 4: _t->minChanged((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 5: _t->updatingChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setCurve((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 7: _t->setFrom((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 8: _t->setTo((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 9: _t->setNPoints((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setUpdating((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->pointsEvaluateStart(); break;
        case 12: _t->pointsEvaluateFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ParametrizedCurveModel::*_t)(qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParametrizedCurveModel::fromChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ParametrizedCurveModel::*_t)(qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParametrizedCurveModel::toChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ParametrizedCurveModel::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParametrizedCurveModel::nPointsChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ParametrizedCurveModel::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParametrizedCurveModel::maxChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ParametrizedCurveModel::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParametrizedCurveModel::minChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ParametrizedCurveModel::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParametrizedCurveModel::updatingChanged)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ParametrizedCurveModel *_t = static_cast<ParametrizedCurveModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->from(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->to(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->nPoints(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->updating(); break;
        case 4: *reinterpret_cast< QPointF*>(_v) = _t->max(); break;
        case 5: *reinterpret_cast< QPointF*>(_v) = _t->min(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ParametrizedCurveModel *_t = static_cast<ParametrizedCurveModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFrom(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setTo(*reinterpret_cast< qreal*>(_v)); break;
        case 2: _t->setNPoints(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ParametrizedCurveModel::staticMetaObject = {
    { &BaseCurveModel::staticMetaObject, qt_meta_stringdata_ParametrizedCurveModel.data,
      qt_meta_data_ParametrizedCurveModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ParametrizedCurveModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParametrizedCurveModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ParametrizedCurveModel.stringdata0))
        return static_cast<void*>(this);
    return BaseCurveModel::qt_metacast(_clname);
}

int ParametrizedCurveModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseCurveModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ParametrizedCurveModel::fromChanged(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ParametrizedCurveModel::toChanged(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ParametrizedCurveModel::nPointsChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ParametrizedCurveModel::maxChanged(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ParametrizedCurveModel::minChanged(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ParametrizedCurveModel::updatingChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
