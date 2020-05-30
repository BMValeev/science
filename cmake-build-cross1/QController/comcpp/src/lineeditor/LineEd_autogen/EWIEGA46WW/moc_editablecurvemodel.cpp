/****************************************************************************
** Meta object code from reading C++ file 'editablecurvemodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../QController/comcpp/src/lineeditor/editablecurvemodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editablecurvemodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditableCurveModel_t {
    QByteArrayData data[4];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditableCurveModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditableCurveModel_t qt_meta_stringdata_EditableCurveModel = {
    {
QT_MOC_LITERAL(0, 0, 18), // "EditableCurveModel"
QT_MOC_LITERAL(1, 19, 8), // "setCurve"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5) // "curve"

    },
    "EditableCurveModel\0setCurve\0\0curve"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditableCurveModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QObjectStar,    3,

       0        // eod
};

void EditableCurveModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditableCurveModel *_t = static_cast<EditableCurveModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setCurve((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject EditableCurveModel::staticMetaObject = {
    { &BaseCurveModel::staticMetaObject, qt_meta_stringdata_EditableCurveModel.data,
      qt_meta_data_EditableCurveModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EditableCurveModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditableCurveModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditableCurveModel.stringdata0))
        return static_cast<void*>(this);
    return BaseCurveModel::qt_metacast(_clname);
}

int EditableCurveModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseCurveModel::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
