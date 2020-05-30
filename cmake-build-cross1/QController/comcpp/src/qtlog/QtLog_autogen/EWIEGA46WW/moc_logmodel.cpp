/****************************************************************************
** Meta object code from reading C++ file 'logmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../QController/comcpp/src/qtlog/logmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtLog__LogModel_t {
    QByteArrayData data[9];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtLog__LogModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtLog__LogModel_t qt_meta_stringdata_QtLog__LogModel = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QtLog::LogModel"
QT_MOC_LITERAL(1, 16, 19), // "removeFirstMessages"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 5), // "count"
QT_MOC_LITERAL(4, 43, 11), // "addMessages"
QT_MOC_LITERAL(5, 55, 17), // "QList<LogMessage>"
QT_MOC_LITERAL(6, 73, 8), // "messages"
QT_MOC_LITERAL(7, 82, 10), // "flushModel"
QT_MOC_LITERAL(8, 93, 11) // "bufferWatch"

    },
    "QtLog::LogModel\0removeFirstMessages\0"
    "\0count\0addMessages\0QList<LogMessage>\0"
    "messages\0flushModel\0bufferWatch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtLog__LogModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       7,    0,   40,    2, 0x0a /* Public */,
       8,    0,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtLog::LogModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LogModel *_t = static_cast<LogModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->removeFirstMessages((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->addMessages((*reinterpret_cast< QList<LogMessage>(*)>(_a[1]))); break;
        case 2: _t->flushModel(); break;
        case 3: _t->bufferWatch(); break;
        default: ;
        }
    }
}

const QMetaObject QtLog::LogModel::staticMetaObject = {
    { &LogModelBase::staticMetaObject, qt_meta_stringdata_QtLog__LogModel.data,
      qt_meta_data_QtLog__LogModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtLog::LogModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtLog::LogModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtLog__LogModel.stringdata0))
        return static_cast<void*>(this);
    return LogModelBase::qt_metacast(_clname);
}

int QtLog::LogModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LogModelBase::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
