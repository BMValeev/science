/****************************************************************************
** Meta object code from reading C++ file 'qenumerableint.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../QController/comcpp/src/enumerables/qenumerableint.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qenumerableint.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QEnumerableInt_t {
    QByteArrayData data[12];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QEnumerableInt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QEnumerableInt_t qt_meta_stringdata_QEnumerableInt = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QEnumerableInt"
QT_MOC_LITERAL(1, 15, 12), // "valueChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "value"
QT_MOC_LITERAL(4, 35, 4), // "plus"
QT_MOC_LITERAL(5, 40, 1), // "n"
QT_MOC_LITERAL(6, 42, 5), // "minus"
QT_MOC_LITERAL(7, 48, 13), // "requestChange"
QT_MOC_LITERAL(8, 62, 3), // "val"
QT_MOC_LITERAL(9, 66, 3), // "max"
QT_MOC_LITERAL(10, 70, 3), // "min"
QT_MOC_LITERAL(11, 74, 7) // "valPerc"

    },
    "QEnumerableInt\0valueChanged\0\0value\0"
    "plus\0n\0minus\0requestChange\0val\0max\0"
    "min\0valPerc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QEnumerableInt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       4,   58, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   47,    2, 0x0a /* Public */,
       4,    0,   50,    2, 0x2a /* Public | MethodCloned */,
       6,    1,   51,    2, 0x0a /* Public */,
       6,    0,   54,    2, 0x2a /* Public | MethodCloned */,
       7,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00495003,
       9, QMetaType::Int, 0x00095401,
      10, QMetaType::Int, 0x00095401,
      11, QMetaType::Double, 0x00495001,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,

       0        // eod
};

void QEnumerableInt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QEnumerableInt *_t = static_cast<QEnumerableInt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->plus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->plus(); break;
        case 3: _t->minus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->minus(); break;
        case 5: _t->requestChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QEnumerableInt::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEnumerableInt::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QEnumerableInt *_t = static_cast<QEnumerableInt *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->value(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->max(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->min(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->valPerc(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QEnumerableInt *_t = static_cast<QEnumerableInt *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->requestChange(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QEnumerableInt::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QEnumerableInt.data,
      qt_meta_data_QEnumerableInt,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QEnumerableInt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QEnumerableInt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QEnumerableInt.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Enumerable<int>"))
        return static_cast< Enumerable<int>*>(this);
    return QObject::qt_metacast(_clname);
}

int QEnumerableInt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QEnumerableInt::valueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
