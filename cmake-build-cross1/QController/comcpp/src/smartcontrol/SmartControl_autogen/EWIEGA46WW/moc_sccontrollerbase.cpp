/****************************************************************************
** Meta object code from reading C++ file 'sccontrollerbase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../QController/comcpp/src/smartcontrol/sccontrollerbase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sccontrollerbase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SCControllerBase_t {
    QByteArrayData data[14];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SCControllerBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SCControllerBase_t qt_meta_stringdata_SCControllerBase = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SCControllerBase"
QT_MOC_LITERAL(1, 17, 13), // "launchBonding"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "deleteOldBonding"
QT_MOC_LITERAL(4, 49, 16), // "connectedChanged"
QT_MOC_LITERAL(5, 66, 9), // "connected"
QT_MOC_LITERAL(6, 76, 22), // "bondedDeviceCntChanged"
QT_MOC_LITERAL(7, 99, 15), // "bondedDeviceCnt"
QT_MOC_LITERAL(8, 115, 5), // "start"
QT_MOC_LITERAL(9, 121, 6), // "finish"
QT_MOC_LITERAL(10, 128, 16), // "checkNewMessages"
QT_MOC_LITERAL(11, 145, 22), // "readBondedDevicesCount"
QT_MOC_LITERAL(12, 168, 17), // "launchBondingImpl"
QT_MOC_LITERAL(13, 186, 18) // "setBondedDeviceCnt"

    },
    "SCControllerBase\0launchBonding\0\0"
    "deleteOldBonding\0connectedChanged\0"
    "connected\0bondedDeviceCntChanged\0"
    "bondedDeviceCnt\0start\0finish\0"
    "checkNewMessages\0readBondedDevicesCount\0"
    "launchBondingImpl\0setBondedDeviceCnt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SCControllerBase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       2,   78, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   68,    2, 0x0a /* Public */,
       9,    0,   69,    2, 0x0a /* Public */,
      10,    0,   70,    2, 0x0a /* Public */,
      11,    0,   71,    2, 0x0a /* Public */,
      12,    1,   72,    2, 0x0a /* Public */,
      13,    1,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    7,

 // properties: name, type, flags
       5, QMetaType::Bool, 0x00495001,
       7, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       1,
       2,

       0        // eod
};

void SCControllerBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SCControllerBase *_t = static_cast<SCControllerBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->launchBonding((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->connectedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->bondedDeviceCntChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->start(); break;
        case 4: _t->finish(); break;
        case 5: _t->checkNewMessages(); break;
        case 6: _t->readBondedDevicesCount(); break;
        case 7: _t->launchBondingImpl((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setBondedDeviceCnt((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SCControllerBase::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SCControllerBase::launchBonding)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SCControllerBase::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SCControllerBase::connectedChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SCControllerBase::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SCControllerBase::bondedDeviceCntChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        SCControllerBase *_t = static_cast<SCControllerBase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->connected(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->bondedDeviceCnt(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        SCControllerBase *_t = static_cast<SCControllerBase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setBondedDeviceCnt(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject SCControllerBase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SCControllerBase.data,
      qt_meta_data_SCControllerBase,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SCControllerBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SCControllerBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SCControllerBase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SCControllerBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
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
void SCControllerBase::launchBonding(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SCControllerBase::connectedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SCControllerBase::bondedDeviceCntChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
