/****************************************************************************
** Meta object code from reading C++ file 'qiorequestresponse.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../QController/comcpp/src/qio/qiorequestresponse.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qiorequestresponse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QIORequestResponse_t {
    QByteArrayData data[15];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QIORequestResponse_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QIORequestResponse_t qt_meta_stringdata_QIORequestResponse = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QIORequestResponse"
QT_MOC_LITERAL(1, 19, 4), // "rMsg"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "QVector<uint8_t>"
QT_MOC_LITERAL(4, 42, 7), // "payload"
QT_MOC_LITERAL(5, 50, 6), // "onByte"
QT_MOC_LITERAL(6, 57, 7), // "uint8_t"
QT_MOC_LITERAL(7, 65, 4), // "byte"
QT_MOC_LITERAL(8, 70, 5), // "onMsg"
QT_MOC_LITERAL(9, 76, 5), // "mOnRx"
QT_MOC_LITERAL(10, 82, 4), // "data"
QT_MOC_LITERAL(11, 87, 16), // "mOnTransFinished"
QT_MOC_LITERAL(12, 104, 11), // "mStartTrans"
QT_MOC_LITERAL(13, 116, 17), // "QIOTransactionPtr"
QT_MOC_LITERAL(14, 134, 5) // "trans"

    },
    "QIORequestResponse\0rMsg\0\0QVector<uint8_t>\0"
    "payload\0onByte\0uint8_t\0byte\0onMsg\0"
    "mOnRx\0data\0mOnTransFinished\0mStartTrans\0"
    "QIOTransactionPtr\0trans"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QIORequestResponse[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x09 /* Protected */,
       8,    1,   50,    2, 0x09 /* Protected */,
       9,    1,   53,    2, 0x08 /* Private */,
      11,    0,   56,    2, 0x08 /* Private */,
      12,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void QIORequestResponse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QIORequestResponse *_t = static_cast<QIORequestResponse *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rMsg((*reinterpret_cast< const QVector<uint8_t>(*)>(_a[1]))); break;
        case 1: _t->onByte((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 2: _t->onMsg((*reinterpret_cast< const QVector<uint8_t>(*)>(_a[1]))); break;
        case 3: _t->mOnRx((*reinterpret_cast< QVector<uint8_t>(*)>(_a[1]))); break;
        case 4: _t->mOnTransFinished(); break;
        case 5: _t->mStartTrans((*reinterpret_cast< QIOTransactionPtr(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QIORequestResponse::*_t)(const QVector<uint8_t> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QIORequestResponse::rMsg)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QIORequestResponse::staticMetaObject = {
    { &QtLog::QLoggableObject::staticMetaObject, qt_meta_stringdata_QIORequestResponse.data,
      qt_meta_data_QIORequestResponse,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QIORequestResponse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QIORequestResponse::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QIORequestResponse.stringdata0))
        return static_cast<void*>(this);
    return QtLog::QLoggableObject::qt_metacast(_clname);
}

int QIORequestResponse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtLog::QLoggableObject::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void QIORequestResponse::rMsg(const QVector<uint8_t> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
