/****************************************************************************
** Meta object code from reading C++ file 'splinecurve.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../QController/comcpp/src/lineeditor/splinecurve.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'splinecurve.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SplineCurve_t {
    QByteArrayData data[8];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SplineCurve_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SplineCurve_t qt_meta_stringdata_SplineCurve = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SplineCurve"
QT_MOC_LITERAL(1, 12, 18), // "interpolantChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7), // "Spline*"
QT_MOC_LITERAL(4, 40, 11), // "interpolant"
QT_MOC_LITERAL(5, 52, 17), // "updateInterpolant"
QT_MOC_LITERAL(6, 70, 17), // "QVector<QPointF>&"
QT_MOC_LITERAL(7, 88, 2) // "ps"

    },
    "SplineCurve\0interpolantChanged\0\0Spline*\0"
    "interpolant\0updateInterpolant\0"
    "QVector<QPointF>&\0ps"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SplineCurve[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void SplineCurve::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SplineCurve *_t = static_cast<SplineCurve *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->interpolantChanged((*reinterpret_cast< Spline*(*)>(_a[1]))); break;
        case 1: _t->updateInterpolant((*reinterpret_cast< QVector<QPointF>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Spline* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SplineCurve::*_t)(Spline * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SplineCurve::interpolantChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SplineCurve::staticMetaObject = {
    { &BaseCurve::staticMetaObject, qt_meta_stringdata_SplineCurve.data,
      qt_meta_data_SplineCurve,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SplineCurve::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SplineCurve::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SplineCurve.stringdata0))
        return static_cast<void*>(this);
    return BaseCurve::qt_metacast(_clname);
}

int SplineCurve::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseCurve::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void SplineCurve::interpolantChanged(Spline * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
