/****************************************************************************
** Meta object code from reading C++ file 'qloggableobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../QController/comcpp/src/qtlog/qloggableobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qloggableobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtLog__QLoggableObject_t {
    QByteArrayData data[8];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtLog__QLoggableObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtLog__QLoggableObject_t qt_meta_stringdata_QtLog__QLoggableObject = {
    {
QT_MOC_LITERAL(0, 0, 22), // "QtLog::QLoggableObject"
QT_MOC_LITERAL(1, 23, 7), // "message"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "_msg"
QT_MOC_LITERAL(4, 37, 9), // "QtMsgType"
QT_MOC_LITERAL(5, 47, 4), // "type"
QT_MOC_LITERAL(6, 52, 17), // "QLoggingCategory*"
QT_MOC_LITERAL(7, 70, 8) // "category"

    },
    "QtLog::QLoggableObject\0message\0\0_msg\0"
    "QtMsgType\0type\0QLoggingCategory*\0"
    "category"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtLog__QLoggableObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 6,    3,    5,    7,

       0        // eod
};

void QtLog::QLoggableObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QLoggableObject *_t = static_cast<QLoggableObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->message((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QtMsgType(*)>(_a[2])),(*reinterpret_cast< QLoggingCategory*(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QLoggableObject::*_t)(QString , QtMsgType , QLoggingCategory * ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLoggableObject::message)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QtLog::QLoggableObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtLog__QLoggableObject.data,
      qt_meta_data_QtLog__QLoggableObject,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtLog::QLoggableObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtLog::QLoggableObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtLog__QLoggableObject.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QLoggable"))
        return static_cast< QLoggable*>(this);
    return QObject::qt_metacast(_clname);
}

int QtLog::QLoggableObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QtLog::QLoggableObject::message(QString _t1, QtMsgType _t2, QLoggingCategory * _t3)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(const_cast< QtLog::QLoggableObject *>(this), &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
