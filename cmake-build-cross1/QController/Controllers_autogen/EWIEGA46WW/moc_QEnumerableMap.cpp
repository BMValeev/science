/****************************************************************************
** Meta object code from reading C++ file 'QEnumerableMap.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../QController/QEnumerableMap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QEnumerableMap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QEnumerableMap_t {
    QByteArrayData data[12];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QEnumerableMap_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QEnumerableMap_t qt_meta_stringdata_QEnumerableMap = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QEnumerableMap"
QT_MOC_LITERAL(1, 15, 15), // "curValueChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "val"
QT_MOC_LITERAL(4, 36, 8), // "curValue"
QT_MOC_LITERAL(5, 45, 8), // "maxValue"
QT_MOC_LITERAL(6, 54, 8), // "allNames"
QT_MOC_LITERAL(7, 63, 14), // "QList<QString>"
QT_MOC_LITERAL(8, 78, 8), // "minValue"
QT_MOC_LITERAL(9, 87, 13), // "writeCurValue"
QT_MOC_LITERAL(10, 101, 5), // "value"
QT_MOC_LITERAL(11, 107, 8) // "setParam"

    },
    "QEnumerableMap\0curValueChanged\0\0val\0"
    "curValue\0maxValue\0allNames\0QList<QString>\0"
    "minValue\0writeCurValue\0value\0setParam"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QEnumerableMap[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       4,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   52,    2, 0x0a /* Public */,
       5,    0,   53,    2, 0x0a /* Public */,
       6,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,
       9,    1,   56,    2, 0x0a /* Public */,
      11,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,

 // slots: parameters
    QMetaType::UInt,
    QMetaType::UInt,
    0x80000000 | 7,
    QMetaType::UInt,
    QMetaType::Void, QMetaType::UInt,   10,
    QMetaType::Bool, QMetaType::UInt,    3,

 // properties: name, type, flags
       4, QMetaType::UInt, 0x00495003,
       5, QMetaType::UInt, 0x00095001,
       8, QMetaType::UInt, 0x00095001,
       6, 0x80000000 | 7, 0x00095009,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,

       0        // eod
};

void QEnumerableMap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QEnumerableMap *_t = static_cast<QEnumerableMap *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->curValueChanged((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: { uint _r = _t->curValue();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 2: { uint _r = _t->maxValue();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 3: { QList<QString> _r = _t->allNames();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 4: { uint _r = _t->minValue();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->writeCurValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 6: { bool _r = _t->setParam((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QEnumerableMap::*_t)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEnumerableMap::curValueChanged)) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QEnumerableMap *_t = static_cast<QEnumerableMap *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< uint*>(_v) = _t->curValue(); break;
        case 1: *reinterpret_cast< uint*>(_v) = _t->maxValue(); break;
        case 2: *reinterpret_cast< uint*>(_v) = _t->minValue(); break;
        case 3: *reinterpret_cast< QList<QString>*>(_v) = _t->allNames(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QEnumerableMap *_t = static_cast<QEnumerableMap *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->writeCurValue(*reinterpret_cast< uint*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QEnumerableMap::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QEnumerableMap.data,
      qt_meta_data_QEnumerableMap,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QEnumerableMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QEnumerableMap::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QEnumerableMap.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QEnumerableMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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
void QEnumerableMap::curValueChanged(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QEnumerableInt_t {
    QByteArrayData data[8];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QEnumerableInt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QEnumerableInt_t qt_meta_stringdata_QEnumerableInt = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QEnumerableInt"
QT_MOC_LITERAL(1, 15, 13), // "curValChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 3), // "val"
QT_MOC_LITERAL(4, 34, 6), // "maxVal"
QT_MOC_LITERAL(5, 41, 6), // "minVal"
QT_MOC_LITERAL(6, 48, 8), // "writeVal"
QT_MOC_LITERAL(7, 57, 8) // "setParam"

    },
    "QEnumerableInt\0curValChanged\0\0val\0"
    "maxVal\0minVal\0writeVal\0setParam"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QEnumerableInt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       3,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   47,    2, 0x0a /* Public */,
       4,    0,   48,    2, 0x0a /* Public */,
       5,    0,   49,    2, 0x0a /* Public */,
       6,    1,   50,    2, 0x0a /* Public */,
       7,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,

 // slots: parameters
    QMetaType::UInt,
    QMetaType::UInt,
    QMetaType::UInt,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Bool, QMetaType::UInt,    3,

 // properties: name, type, flags
       3, QMetaType::UInt, 0x00495003,
       4, QMetaType::UInt, 0x00095001,
       5, QMetaType::UInt, 0x00095001,

 // properties: notify_signal_id
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
        case 0: _t->curValChanged((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: { uint _r = _t->val();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 2: { uint _r = _t->maxVal();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 3: { uint _r = _t->minVal();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->writeVal((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 5: { bool _r = _t->setParam((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QEnumerableInt::*_t)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEnumerableInt::curValChanged)) {
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
        case 0: *reinterpret_cast< uint*>(_v) = _t->val(); break;
        case 1: *reinterpret_cast< uint*>(_v) = _t->maxVal(); break;
        case 2: *reinterpret_cast< uint*>(_v) = _t->minVal(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QEnumerableInt *_t = static_cast<QEnumerableInt *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->writeVal(*reinterpret_cast< uint*>(_v)); break;
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
void QEnumerableInt::curValChanged(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QEnumerableBool_t {
    QByteArrayData data[6];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QEnumerableBool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QEnumerableBool_t qt_meta_stringdata_QEnumerableBool = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QEnumerableBool"
QT_MOC_LITERAL(1, 16, 13), // "curValChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 3), // "val"
QT_MOC_LITERAL(4, 35, 8), // "writeVal"
QT_MOC_LITERAL(5, 44, 8) // "setParam"

    },
    "QEnumerableBool\0curValChanged\0\0val\0"
    "writeVal\0setParam"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QEnumerableBool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   37,    2, 0x0a /* Public */,
       4,    1,   38,    2, 0x0a /* Public */,
       5,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Bool, QMetaType::Bool,    3,

 // properties: name, type, flags
       3, QMetaType::Bool, 0x00495003,

 // properties: notify_signal_id
       0,

       0        // eod
};

void QEnumerableBool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QEnumerableBool *_t = static_cast<QEnumerableBool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->curValChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: { bool _r = _t->val();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->writeVal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: { bool _r = _t->setParam((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QEnumerableBool::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEnumerableBool::curValChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QEnumerableBool *_t = static_cast<QEnumerableBool *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->val(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QEnumerableBool *_t = static_cast<QEnumerableBool *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->writeVal(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QEnumerableBool::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QEnumerableBool.data,
      qt_meta_data_QEnumerableBool,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QEnumerableBool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QEnumerableBool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QEnumerableBool.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QEnumerableBool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QEnumerableBool::curValChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QEnumerableDate_t {
    QByteArrayData data[19];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QEnumerableDate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QEnumerableDate_t qt_meta_stringdata_QEnumerableDate = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QEnumerableDate"
QT_MOC_LITERAL(1, 16, 10), // "minChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "val"
QT_MOC_LITERAL(4, 32, 11), // "hourChanged"
QT_MOC_LITERAL(5, 44, 10), // "dayChanged"
QT_MOC_LITERAL(6, 55, 12), // "monthChanged"
QT_MOC_LITERAL(7, 68, 11), // "yearChanged"
QT_MOC_LITERAL(8, 80, 3), // "min"
QT_MOC_LITERAL(9, 84, 4), // "hour"
QT_MOC_LITERAL(10, 89, 3), // "day"
QT_MOC_LITERAL(11, 93, 5), // "month"
QT_MOC_LITERAL(12, 99, 4), // "year"
QT_MOC_LITERAL(13, 104, 8), // "writeMin"
QT_MOC_LITERAL(14, 113, 9), // "writeHour"
QT_MOC_LITERAL(15, 123, 8), // "writeDay"
QT_MOC_LITERAL(16, 132, 10), // "writeMonth"
QT_MOC_LITERAL(17, 143, 9), // "writeYear"
QT_MOC_LITERAL(18, 153, 8) // "setParam"

    },
    "QEnumerableDate\0minChanged\0\0val\0"
    "hourChanged\0dayChanged\0monthChanged\0"
    "yearChanged\0min\0hour\0day\0month\0year\0"
    "writeMin\0writeHour\0writeDay\0writeMonth\0"
    "writeYear\0setParam"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QEnumerableDate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       5,  130, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    1,   97,    2, 0x06 /* Public */,
       5,    1,  100,    2, 0x06 /* Public */,
       6,    1,  103,    2, 0x06 /* Public */,
       7,    1,  106,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  109,    2, 0x0a /* Public */,
       9,    0,  110,    2, 0x0a /* Public */,
      10,    0,  111,    2, 0x0a /* Public */,
      11,    0,  112,    2, 0x0a /* Public */,
      12,    0,  113,    2, 0x0a /* Public */,
      13,    1,  114,    2, 0x0a /* Public */,
      14,    1,  117,    2, 0x0a /* Public */,
      15,    1,  120,    2, 0x0a /* Public */,
      16,    1,  123,    2, 0x0a /* Public */,
      17,    1,  126,    2, 0x0a /* Public */,
      18,    0,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Bool,

 // properties: name, type, flags
       8, QMetaType::Int, 0x00495003,
       9, QMetaType::Int, 0x00495003,
      10, QMetaType::Int, 0x00495003,
      11, QMetaType::Int, 0x00495003,
      12, QMetaType::Int, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void QEnumerableDate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QEnumerableDate *_t = static_cast<QEnumerableDate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->minChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->hourChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->dayChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->monthChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->yearChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: { int _r = _t->min();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->hour();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->day();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->month();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->year();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->writeMin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->writeHour((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->writeDay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->writeMonth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->writeYear((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: { bool _r = _t->setParam();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QEnumerableDate::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEnumerableDate::minChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QEnumerableDate::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEnumerableDate::hourChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QEnumerableDate::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEnumerableDate::dayChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QEnumerableDate::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEnumerableDate::monthChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QEnumerableDate::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEnumerableDate::yearChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QEnumerableDate *_t = static_cast<QEnumerableDate *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->min(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->hour(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->day(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->month(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->year(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QEnumerableDate *_t = static_cast<QEnumerableDate *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->writeMin(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->writeHour(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->writeDay(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->writeMonth(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->writeYear(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QEnumerableDate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QEnumerableDate.data,
      qt_meta_data_QEnumerableDate,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QEnumerableDate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QEnumerableDate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QEnumerableDate.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QEnumerableDate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QEnumerableDate::minChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QEnumerableDate::hourChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QEnumerableDate::dayChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QEnumerableDate::monthChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QEnumerableDate::yearChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
struct qt_meta_stringdata_QEnumerableIP_t {
    QByteArrayData data[16];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QEnumerableIP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QEnumerableIP_t qt_meta_stringdata_QEnumerableIP = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QEnumerableIP"
QT_MOC_LITERAL(1, 14, 12), // "byte1Changed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "val"
QT_MOC_LITERAL(4, 32, 12), // "byte2Changed"
QT_MOC_LITERAL(5, 45, 12), // "byte3Changed"
QT_MOC_LITERAL(6, 58, 12), // "byte4Changed"
QT_MOC_LITERAL(7, 71, 5), // "byte1"
QT_MOC_LITERAL(8, 77, 5), // "byte2"
QT_MOC_LITERAL(9, 83, 5), // "byte3"
QT_MOC_LITERAL(10, 89, 5), // "byte4"
QT_MOC_LITERAL(11, 95, 10), // "writeByte1"
QT_MOC_LITERAL(12, 106, 10), // "writeByte2"
QT_MOC_LITERAL(13, 117, 10), // "writeByte3"
QT_MOC_LITERAL(14, 128, 10), // "writeByte4"
QT_MOC_LITERAL(15, 139, 8) // "setParam"

    },
    "QEnumerableIP\0byte1Changed\0\0val\0"
    "byte2Changed\0byte3Changed\0byte4Changed\0"
    "byte1\0byte2\0byte3\0byte4\0writeByte1\0"
    "writeByte2\0writeByte3\0writeByte4\0"
    "setParam"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QEnumerableIP[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       4,  108, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       5,    1,   85,    2, 0x06 /* Public */,
       6,    1,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   91,    2, 0x0a /* Public */,
       8,    0,   92,    2, 0x0a /* Public */,
       9,    0,   93,    2, 0x0a /* Public */,
      10,    0,   94,    2, 0x0a /* Public */,
      11,    1,   95,    2, 0x0a /* Public */,
      12,    1,   98,    2, 0x0a /* Public */,
      13,    1,  101,    2, 0x0a /* Public */,
      14,    1,  104,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar,    3,
    QMetaType::Void, QMetaType::UChar,    3,
    QMetaType::Void, QMetaType::UChar,    3,
    QMetaType::Void, QMetaType::UChar,    3,

 // slots: parameters
    QMetaType::UChar,
    QMetaType::UChar,
    QMetaType::UChar,
    QMetaType::UChar,
    QMetaType::Void, QMetaType::UChar,    3,
    QMetaType::Void, QMetaType::UChar,    3,
    QMetaType::Void, QMetaType::UChar,    3,
    QMetaType::Void, QMetaType::UChar,    3,
    QMetaType::Bool,

 // properties: name, type, flags
       7, QMetaType::UChar, 0x00495003,
       8, QMetaType::UChar, 0x00495003,
       9, QMetaType::UChar, 0x00495003,
      10, QMetaType::UChar, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void QEnumerableIP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QEnumerableIP *_t = static_cast<QEnumerableIP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->byte1Changed((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 1: _t->byte2Changed((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 2: _t->byte3Changed((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 3: _t->byte4Changed((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 4: { unsigned char _r = _t->byte1();
            if (_a[0]) *reinterpret_cast< unsigned char*>(_a[0]) = std::move(_r); }  break;
        case 5: { unsigned char _r = _t->byte2();
            if (_a[0]) *reinterpret_cast< unsigned char*>(_a[0]) = std::move(_r); }  break;
        case 6: { unsigned char _r = _t->byte3();
            if (_a[0]) *reinterpret_cast< unsigned char*>(_a[0]) = std::move(_r); }  break;
        case 7: { unsigned char _r = _t->byte4();
            if (_a[0]) *reinterpret_cast< unsigned char*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->writeByte1((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 9: _t->writeByte2((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 10: _t->writeByte3((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 11: _t->writeByte4((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 12: { bool _r = _t->setParam();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QEnumerableIP::*_t)(unsigned char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEnumerableIP::byte1Changed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QEnumerableIP::*_t)(unsigned char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEnumerableIP::byte2Changed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QEnumerableIP::*_t)(unsigned char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEnumerableIP::byte3Changed)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QEnumerableIP::*_t)(unsigned char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QEnumerableIP::byte4Changed)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QEnumerableIP *_t = static_cast<QEnumerableIP *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< unsigned char*>(_v) = _t->byte1(); break;
        case 1: *reinterpret_cast< unsigned char*>(_v) = _t->byte2(); break;
        case 2: *reinterpret_cast< unsigned char*>(_v) = _t->byte3(); break;
        case 3: *reinterpret_cast< unsigned char*>(_v) = _t->byte4(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QEnumerableIP *_t = static_cast<QEnumerableIP *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->writeByte1(*reinterpret_cast< unsigned char*>(_v)); break;
        case 1: _t->writeByte2(*reinterpret_cast< unsigned char*>(_v)); break;
        case 2: _t->writeByte3(*reinterpret_cast< unsigned char*>(_v)); break;
        case 3: _t->writeByte4(*reinterpret_cast< unsigned char*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QEnumerableIP::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QEnumerableIP.data,
      qt_meta_data_QEnumerableIP,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QEnumerableIP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QEnumerableIP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QEnumerableIP.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QEnumerableIP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void QEnumerableIP::byte1Changed(unsigned char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QEnumerableIP::byte2Changed(unsigned char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QEnumerableIP::byte3Changed(unsigned char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QEnumerableIP::byte4Changed(unsigned char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
