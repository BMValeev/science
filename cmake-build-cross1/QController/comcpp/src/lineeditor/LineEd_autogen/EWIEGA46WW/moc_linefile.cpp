/****************************************************************************
** Meta object code from reading C++ file 'linefile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../QController/comcpp/src/lineeditor/linefile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linefile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LineFile_t {
    QByteArrayData data[13];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LineFile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LineFile_t qt_meta_stringdata_LineFile = {
    {
QT_MOC_LITERAL(0, 0, 8), // "LineFile"
QT_MOC_LITERAL(1, 9, 19), // "lastSaveTimeChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "lastSaveTime"
QT_MOC_LITERAL(4, 43, 11), // "fileChanged"
QT_MOC_LITERAL(5, 55, 4), // "file"
QT_MOC_LITERAL(6, 60, 26), // "synchronizeOnChangeChanged"
QT_MOC_LITERAL(7, 87, 19), // "synchronizeOnChange"
QT_MOC_LITERAL(8, 107, 7), // "setFile"
QT_MOC_LITERAL(9, 115, 4), // "save"
QT_MOC_LITERAL(10, 120, 22), // "setSynchronizeOnChange"
QT_MOC_LITERAL(11, 143, 4), // "load"
QT_MOC_LITERAL(12, 148, 4) // "path"

    },
    "LineFile\0lastSaveTimeChanged\0\0"
    "lastSaveTime\0fileChanged\0file\0"
    "synchronizeOnChangeChanged\0"
    "synchronizeOnChange\0setFile\0save\0"
    "setSynchronizeOnChange\0load\0path"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LineFile[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       3,   76, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   63,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,
      11,    1,   70,    2, 0x08 /* Private */,
       9,    1,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,

 // properties: name, type, flags
       5, QMetaType::QString, 0x00495103,
       3, QMetaType::QString, 0x00495001,
       7, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       1,
       0,
       2,

       0        // eod
};

void LineFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LineFile *_t = static_cast<LineFile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lastSaveTimeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->fileChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->synchronizeOnChangeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->save(); break;
        case 5: _t->setSynchronizeOnChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->load((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->save((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (LineFile::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LineFile::lastSaveTimeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LineFile::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LineFile::fileChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LineFile::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LineFile::synchronizeOnChangeChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        LineFile *_t = static_cast<LineFile *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->file(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->lastSaveTime(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->synchronizeOnChange(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        LineFile *_t = static_cast<LineFile *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFile(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setSynchronizeOnChange(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject LineFile::staticMetaObject = {
    { &SplineCurve::staticMetaObject, qt_meta_stringdata_LineFile.data,
      qt_meta_data_LineFile,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LineFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LineFile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LineFile.stringdata0))
        return static_cast<void*>(this);
    return SplineCurve::qt_metacast(_clname);
}

int LineFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SplineCurve::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
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
void LineFile::lastSaveTimeChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LineFile::fileChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LineFile::synchronizeOnChangeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
