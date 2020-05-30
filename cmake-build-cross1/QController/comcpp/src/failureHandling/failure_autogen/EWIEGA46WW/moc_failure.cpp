/****************************************************************************
** Meta object code from reading C++ file 'failure.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../QController/comcpp/src/failureHandling/failure.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'failure.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Failure_t {
    QByteArrayData data[10];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Failure_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Failure_t qt_meta_stringdata_Failure = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Failure"
QT_MOC_LITERAL(1, 8, 13), // "activeChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "active"
QT_MOC_LITERAL(4, 30, 21), // "activeIntervalChanged"
QT_MOC_LITERAL(5, 52, 14), // "activeInterval"
QT_MOC_LITERAL(6, 67, 9), // "setActive"
QT_MOC_LITERAL(7, 77, 17), // "setActiveInterval"
QT_MOC_LITERAL(8, 95, 4), // "code"
QT_MOC_LITERAL(9, 100, 11) // "description"

    },
    "Failure\0activeChanged\0\0active\0"
    "activeIntervalChanged\0activeInterval\0"
    "setActive\0setActiveInterval\0code\0"
    "description"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Failure[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       4,   46, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   40,    2, 0x0a /* Public */,
       7,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // properties: name, type, flags
       8, QMetaType::Int, 0x00095401,
       9, QMetaType::QString, 0x00095401,
       3, QMetaType::Bool, 0x00495103,
       5, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       0,
       0,
       1,

       0        // eod
};

void Failure::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Failure *_t = static_cast<Failure *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->activeIntervalChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setActiveInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Failure::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Failure::activeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Failure::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Failure::activeIntervalChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Failure *_t = static_cast<Failure *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->code(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->description(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->active(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->activeInterval(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Failure *_t = static_cast<Failure *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setActive(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setActiveInterval(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Failure::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Failure.data,
      qt_meta_data_Failure,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Failure::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Failure::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Failure.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Failure::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
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
void Failure::activeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Failure::activeIntervalChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
