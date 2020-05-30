/****************************************************************************
** Meta object code from reading C++ file 'basecurvemodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../QController/comcpp/src/lineeditor/basecurvemodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basecurvemodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BaseCurveModel_t {
    QByteArrayData data[12];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaseCurveModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaseCurveModel_t qt_meta_stringdata_BaseCurveModel = {
    {
QT_MOC_LITERAL(0, 0, 14), // "BaseCurveModel"
QT_MOC_LITERAL(1, 15, 12), // "curveChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "curve"
QT_MOC_LITERAL(4, 35, 14), // "seriesAppended"
QT_MOC_LITERAL(5, 50, 10), // "QXYSeries*"
QT_MOC_LITERAL(6, 61, 6), // "series"
QT_MOC_LITERAL(7, 68, 8), // "setCurve"
QT_MOC_LITERAL(8, 77, 12), // "updateSeries"
QT_MOC_LITERAL(9, 90, 16), // "QVector<QPointF>"
QT_MOC_LITERAL(10, 107, 6), // "points"
QT_MOC_LITERAL(11, 114, 25) // "QQmlListProperty<QObject>"

    },
    "BaseCurveModel\0curveChanged\0\0curve\0"
    "seriesAppended\0QXYSeries*\0series\0"
    "setCurve\0updateSeries\0QVector<QPointF>\0"
    "points\0QQmlListProperty<QObject>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaseCurveModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   45,    2, 0x0a /* Public */,
       8,    1,   48,    2, 0x0a /* Public */,
       8,    2,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QObjectStar,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QObjectStar,    3,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 5,   10,    6,

 // properties: name, type, flags
       3, QMetaType::QObjectStar, 0x00495103,
       6, 0x80000000 | 11, 0x00095009,

 // properties: notify_signal_id
       0,
       0,

       0        // eod
};

void BaseCurveModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BaseCurveModel *_t = static_cast<BaseCurveModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->curveChanged((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 1: _t->seriesAppended((*reinterpret_cast< QXYSeries*(*)>(_a[1]))); break;
        case 2: _t->setCurve((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 3: _t->updateSeries((*reinterpret_cast< const QVector<QPointF>(*)>(_a[1]))); break;
        case 4: _t->updateSeries((*reinterpret_cast< const QVector<QPointF>(*)>(_a[1])),(*reinterpret_cast< QXYSeries*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QXYSeries* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QPointF> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QPointF> >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QXYSeries* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BaseCurveModel::*_t)(QObject * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseCurveModel::curveChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BaseCurveModel::*_t)(QXYSeries * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseCurveModel::seriesAppended)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        BaseCurveModel *_t = static_cast<BaseCurveModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QObject**>(_v) = _t->curve(); break;
        case 1: *reinterpret_cast< QQmlListProperty<QObject>*>(_v) = _t->series(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        BaseCurveModel *_t = static_cast<BaseCurveModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurve(*reinterpret_cast< QObject**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject BaseCurveModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_BaseCurveModel.data,
      qt_meta_data_BaseCurveModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BaseCurveModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaseCurveModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BaseCurveModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int BaseCurveModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BaseCurveModel::curveChanged(QObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BaseCurveModel::seriesAppended(QXYSeries * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
