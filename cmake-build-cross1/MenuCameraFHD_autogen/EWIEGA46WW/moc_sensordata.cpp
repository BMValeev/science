/****************************************************************************
** Meta object code from reading C++ file 'sensordata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../sensordata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sensordata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_sensordata_t {
    QByteArrayData data[11];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_sensordata_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_sensordata_t qt_meta_stringdata_sensordata = {
    {
QT_MOC_LITERAL(0, 0, 10), // "sensordata"
QT_MOC_LITERAL(1, 11, 9), // "renewData"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "reconfigure"
QT_MOC_LITERAL(4, 34, 6), // "reconf"
QT_MOC_LITERAL(5, 41, 3), // "val"
QT_MOC_LITERAL(6, 45, 5), // "CHFIN"
QT_MOC_LITERAL(7, 51, 11), // "renewVector"
QT_MOC_LITERAL(8, 63, 15), // "QVector<float>*"
QT_MOC_LITERAL(9, 79, 8), // "renewPtr"
QT_MOC_LITERAL(10, 88, 6) // "period"

    },
    "sensordata\0renewData\0\0reconfigure\0"
    "reconf\0val\0CHFIN\0renewVector\0"
    "QVector<float>*\0renewPtr\0period"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_sensordata[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    2,   46,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,
       9,    0,   52,    2, 0x0a /* Public */,
      10,    0,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    5,    6,
    0x80000000 | 8,
    QMetaType::UInt,
    QMetaType::Double,

       0        // eod
};

void sensordata::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        sensordata *_t = static_cast<sensordata *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->renewData(); break;
        case 1: _t->reconfigure(); break;
        case 2: _t->reconf((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 3: { QVector<float>* _r = _t->renewVector();
            if (_a[0]) *reinterpret_cast< QVector<float>**>(_a[0]) = std::move(_r); }  break;
        case 4: { uint _r = _t->renewPtr();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 5: { double _r = _t->period();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject sensordata::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_sensordata.data,
      qt_meta_data_sensordata,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *sensordata::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sensordata::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_sensordata.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int sensordata::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
