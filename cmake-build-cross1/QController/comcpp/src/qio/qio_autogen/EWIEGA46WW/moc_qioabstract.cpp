/****************************************************************************
** Meta object code from reading C++ file 'qioabstract.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../QController/comcpp/src/qio/qioabstract.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qioabstract.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QIOAbstract_t {
    QByteArrayData data[27];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QIOAbstract_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QIOAbstract_t qt_meta_stringdata_QIOAbstract = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QIOAbstract"
QT_MOC_LITERAL(1, 12, 8), // "response"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 16), // "QVector<uint8_t>"
QT_MOC_LITERAL(4, 39, 4), // "data"
QT_MOC_LITERAL(5, 44, 7), // "sending"
QT_MOC_LITERAL(6, 52, 5), // "error"
QT_MOC_LITERAL(7, 58, 1), // "s"
QT_MOC_LITERAL(8, 60, 7), // "timeout"
QT_MOC_LITERAL(9, 68, 14), // "runningChanged"
QT_MOC_LITERAL(10, 83, 7), // "running"
QT_MOC_LITERAL(11, 91, 19), // "writeTimeoutChanged"
QT_MOC_LITERAL(12, 111, 12), // "writeTimeout"
QT_MOC_LITERAL(13, 124, 19), // "readIntervalChanged"
QT_MOC_LITERAL(14, 144, 12), // "readInterval"
QT_MOC_LITERAL(15, 157, 5), // "start"
QT_MOC_LITERAL(16, 163, 4), // "stop"
QT_MOC_LITERAL(17, 168, 15), // "setWriteTimeout"
QT_MOC_LITERAL(18, 184, 15), // "setReadInterval"
QT_MOC_LITERAL(19, 200, 5), // "mSend"
QT_MOC_LITERAL(20, 206, 6), // "txData"
QT_MOC_LITERAL(21, 213, 12), // "mOnReadyRead"
QT_MOC_LITERAL(22, 226, 18), // "mOnSerialPortError"
QT_MOC_LITERAL(23, 245, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(24, 274, 19), // "mOnLocalSocketError"
QT_MOC_LITERAL(25, 294, 30), // "QLocalSocket::LocalSocketError"
QT_MOC_LITERAL(26, 325, 10) // "setRunning"

    },
    "QIOAbstract\0response\0\0QVector<uint8_t>\0"
    "data\0sending\0error\0s\0timeout\0"
    "runningChanged\0running\0writeTimeoutChanged\0"
    "writeTimeout\0readIntervalChanged\0"
    "readInterval\0start\0stop\0setWriteTimeout\0"
    "setReadInterval\0mSend\0txData\0mOnReadyRead\0"
    "mOnSerialPortError\0QSerialPort::SerialPortError\0"
    "mOnLocalSocketError\0QLocalSocket::LocalSocketError\0"
    "setRunning"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QIOAbstract[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       3,  136, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       5,    1,   97,    2, 0x06 /* Public */,
       6,    1,  100,    2, 0x06 /* Public */,
       8,    1,  103,    2, 0x06 /* Public */,
       9,    1,  106,    2, 0x06 /* Public */,
      11,    1,  109,    2, 0x06 /* Public */,
      13,    1,  112,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  115,    2, 0x0a /* Public */,
      16,    0,  116,    2, 0x0a /* Public */,
      17,    1,  117,    2, 0x0a /* Public */,
      18,    1,  120,    2, 0x0a /* Public */,
      19,    1,  123,    2, 0x09 /* Protected */,
      21,    0,  126,    2, 0x08 /* Private */,
      22,    1,  127,    2, 0x08 /* Private */,
      24,    1,  130,    2, 0x08 /* Private */,
      26,    1,  133,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, 0x80000000 | 3,   20,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,    6,
    QMetaType::Void, 0x80000000 | 25,    6,
    QMetaType::Void, QMetaType::Bool,   10,

 // properties: name, type, flags
      10, QMetaType::Bool, 0x00495103,
      12, QMetaType::Int, 0x00495103,
      14, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       4,
       5,
       6,

       0        // eod
};

void QIOAbstract::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QIOAbstract *_t = static_cast<QIOAbstract *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->response((*reinterpret_cast< const QVector<uint8_t>(*)>(_a[1]))); break;
        case 1: _t->sending((*reinterpret_cast< const QVector<uint8_t>(*)>(_a[1]))); break;
        case 2: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->timeout((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->runningChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->writeTimeoutChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->readIntervalChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->start(); break;
        case 8: _t->stop(); break;
        case 9: _t->setWriteTimeout((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setReadInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->mSend((*reinterpret_cast< const QVector<uint8_t>(*)>(_a[1]))); break;
        case 12: _t->mOnReadyRead(); break;
        case 13: _t->mOnSerialPortError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 14: _t->mOnLocalSocketError((*reinterpret_cast< QLocalSocket::LocalSocketError(*)>(_a[1]))); break;
        case 15: _t->setRunning((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QIOAbstract::*_t)(const QVector<uint8_t> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QIOAbstract::response)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QIOAbstract::*_t)(const QVector<uint8_t> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QIOAbstract::sending)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QIOAbstract::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QIOAbstract::error)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QIOAbstract::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QIOAbstract::timeout)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QIOAbstract::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QIOAbstract::runningChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (QIOAbstract::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QIOAbstract::writeTimeoutChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (QIOAbstract::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QIOAbstract::readIntervalChanged)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QIOAbstract *_t = static_cast<QIOAbstract *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->running(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->writeTimeout(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->readInterval(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QIOAbstract *_t = static_cast<QIOAbstract *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRunning(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setWriteTimeout(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setReadInterval(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QIOAbstract::staticMetaObject = {
    { &QtLog::QLoggableObject::staticMetaObject, qt_meta_stringdata_QIOAbstract.data,
      qt_meta_data_QIOAbstract,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QIOAbstract::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QIOAbstract::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QIOAbstract.stringdata0))
        return static_cast<void*>(this);
    return QtLog::QLoggableObject::qt_metacast(_clname);
}

int QIOAbstract::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtLog::QLoggableObject::qt_metacall(_c, _id, _a);
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
void QIOAbstract::response(const QVector<uint8_t> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QIOAbstract::sending(const QVector<uint8_t> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QIOAbstract::error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QIOAbstract::timeout(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QIOAbstract::runningChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QIOAbstract::writeTimeoutChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QIOAbstract::readIntervalChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
