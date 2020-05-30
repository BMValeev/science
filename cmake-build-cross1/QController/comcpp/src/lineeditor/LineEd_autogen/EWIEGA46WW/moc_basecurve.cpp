/****************************************************************************
** Meta object code from reading C++ file 'basecurve.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../QController/comcpp/src/lineeditor/basecurve.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basecurve.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BaseCurve_t {
    QByteArrayData data[29];
    char stringdata0[335];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaseCurve_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaseCurve_t qt_meta_stringdata_BaseCurve = {
    {
QT_MOC_LITERAL(0, 0, 9), // "BaseCurve"
QT_MOC_LITERAL(1, 10, 10), // "maxChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "max"
QT_MOC_LITERAL(4, 26, 10), // "minChanged"
QT_MOC_LITERAL(5, 37, 3), // "min"
QT_MOC_LITERAL(6, 41, 21), // "allowRearrangeChanged"
QT_MOC_LITERAL(7, 63, 14), // "allowRearrange"
QT_MOC_LITERAL(8, 78, 13), // "pointsChanged"
QT_MOC_LITERAL(9, 92, 17), // "QVector<QPointF>&"
QT_MOC_LITERAL(10, 110, 6), // "points"
QT_MOC_LITERAL(11, 117, 12), // "pointChanged"
QT_MOC_LITERAL(12, 130, 5), // "index"
QT_MOC_LITERAL(13, 136, 20), // "pointsPreUpdateModel"
QT_MOC_LITERAL(14, 157, 21), // "pointsPostUpdateModel"
QT_MOC_LITERAL(15, 179, 16), // "pointPreInserted"
QT_MOC_LITERAL(16, 196, 17), // "pointPostInserted"
QT_MOC_LITERAL(17, 214, 15), // "pointPreRemoved"
QT_MOC_LITERAL(18, 230, 16), // "pointPostRemoved"
QT_MOC_LITERAL(19, 247, 17), // "setAllowRearrange"
QT_MOC_LITERAL(20, 265, 8), // "addPoint"
QT_MOC_LITERAL(21, 274, 1), // "p"
QT_MOC_LITERAL(22, 276, 15), // "QList<QPointF>&"
QT_MOC_LITERAL(23, 292, 2), // "ps"
QT_MOC_LITERAL(24, 295, 11), // "modifyPoint"
QT_MOC_LITERAL(25, 307, 4), // "newP"
QT_MOC_LITERAL(26, 312, 11), // "removePoint"
QT_MOC_LITERAL(27, 324, 5), // "point"
QT_MOC_LITERAL(28, 330, 4) // "size"

    },
    "BaseCurve\0maxChanged\0\0max\0minChanged\0"
    "min\0allowRearrangeChanged\0allowRearrange\0"
    "pointsChanged\0QVector<QPointF>&\0points\0"
    "pointChanged\0index\0pointsPreUpdateModel\0"
    "pointsPostUpdateModel\0pointPreInserted\0"
    "pointPostInserted\0pointPreRemoved\0"
    "pointPostRemoved\0setAllowRearrange\0"
    "addPoint\0p\0QList<QPointF>&\0ps\0modifyPoint\0"
    "newP\0removePoint\0point\0size"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaseCurve[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       3,  168, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x06 /* Public */,
       4,    1,  117,    2, 0x06 /* Public */,
       6,    1,  120,    2, 0x06 /* Public */,
       8,    1,  123,    2, 0x06 /* Public */,
      11,    1,  126,    2, 0x06 /* Public */,
      13,    1,  129,    2, 0x06 /* Public */,
      14,    0,  132,    2, 0x06 /* Public */,
      15,    1,  133,    2, 0x06 /* Public */,
      16,    0,  136,    2, 0x06 /* Public */,
      17,    1,  137,    2, 0x06 /* Public */,
      18,    0,  140,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    1,  141,    2, 0x0a /* Public */,
      20,    1,  144,    2, 0x0a /* Public */,
      20,    1,  147,    2, 0x0a /* Public */,
      20,    1,  150,    2, 0x0a /* Public */,
      24,    2,  153,    2, 0x0a /* Public */,
      26,    1,  158,    2, 0x0a /* Public */,
      26,    1,  161,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      27,    1,  164,    2, 0x02 /* Public */,
      28,    0,  167,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::QPointF,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::QPointF,   21,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 9,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::QPointF,   12,   25,
    QMetaType::Void, QMetaType::QPointF,   21,
    QMetaType::Void, QMetaType::Int,   12,

 // methods: parameters
    QMetaType::QPointF, QMetaType::Int,   12,
    QMetaType::Int,

 // properties: name, type, flags
       3, QMetaType::QPointF, 0x00495001,
       5, QMetaType::QPointF, 0x00495001,
       7, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void BaseCurve::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BaseCurve *_t = static_cast<BaseCurve *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->maxChanged((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->minChanged((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 2: _t->allowRearrangeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->pointsChanged((*reinterpret_cast< QVector<QPointF>(*)>(_a[1]))); break;
        case 4: _t->pointChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->pointsPreUpdateModel((*reinterpret_cast< QVector<QPointF>(*)>(_a[1]))); break;
        case 6: _t->pointsPostUpdateModel(); break;
        case 7: _t->pointPreInserted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->pointPostInserted(); break;
        case 9: _t->pointPreRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->pointPostRemoved(); break;
        case 11: _t->setAllowRearrange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->addPoint((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 13: _t->addPoint((*reinterpret_cast< QList<QPointF>(*)>(_a[1]))); break;
        case 14: _t->addPoint((*reinterpret_cast< QVector<QPointF>(*)>(_a[1]))); break;
        case 15: _t->modifyPoint((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 16: _t->removePoint((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 17: _t->removePoint((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: { QPointF _r = _t->point((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPointF*>(_a[0]) = std::move(_r); }  break;
        case 19: { int _r = _t->size();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BaseCurve::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseCurve::maxChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BaseCurve::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseCurve::minChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BaseCurve::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseCurve::allowRearrangeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (BaseCurve::*_t)(QVector<QPointF> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseCurve::pointsChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (BaseCurve::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseCurve::pointChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (BaseCurve::*_t)(QVector<QPointF> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseCurve::pointsPreUpdateModel)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (BaseCurve::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseCurve::pointsPostUpdateModel)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (BaseCurve::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseCurve::pointPreInserted)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (BaseCurve::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseCurve::pointPostInserted)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (BaseCurve::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseCurve::pointPreRemoved)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (BaseCurve::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseCurve::pointPostRemoved)) {
                *result = 10;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        BaseCurve *_t = static_cast<BaseCurve *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPointF*>(_v) = _t->max(); break;
        case 1: *reinterpret_cast< QPointF*>(_v) = _t->min(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->allowRearrange(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        BaseCurve *_t = static_cast<BaseCurve *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setAllowRearrange(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject BaseCurve::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BaseCurve.data,
      qt_meta_data_BaseCurve,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BaseCurve::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaseCurve::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BaseCurve.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BaseCurve::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BaseCurve::maxChanged(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BaseCurve::minChanged(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BaseCurve::allowRearrangeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BaseCurve::pointsChanged(QVector<QPointF> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BaseCurve::pointChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void BaseCurve::pointsPreUpdateModel(QVector<QPointF> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void BaseCurve::pointsPostUpdateModel()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void BaseCurve::pointPreInserted(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void BaseCurve::pointPostInserted()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void BaseCurve::pointPreRemoved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void BaseCurve::pointPostRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
