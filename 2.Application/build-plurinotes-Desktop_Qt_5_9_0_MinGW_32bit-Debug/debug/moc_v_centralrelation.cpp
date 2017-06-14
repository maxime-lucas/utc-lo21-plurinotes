/****************************************************************************
** Meta object code from reading C++ file 'v_centralrelation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../plurinotes/views/v_centralrelation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'v_centralrelation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_V_CentralView_t {
    QByteArrayData data[4];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_V_CentralView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_V_CentralView_t qt_meta_stringdata_V_CentralView = {
    {
QT_MOC_LITERAL(0, 0, 13), // "V_CentralView"
QT_MOC_LITERAL(1, 14, 10), // "deleteView"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8) // "editView"

    },
    "V_CentralView\0deleteView\0\0editView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_V_CentralView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void V_CentralView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        V_CentralView *_t = static_cast<V_CentralView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteView(); break;
        case 1: _t->editView(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject V_CentralView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_V_CentralView.data,
      qt_meta_data_V_CentralView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *V_CentralView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *V_CentralView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_V_CentralView.stringdata0))
        return static_cast<void*>(const_cast< V_CentralView*>(this));
    return QWidget::qt_metacast(_clname);
}

int V_CentralView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_V_Centralrelation_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_V_Centralrelation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_V_Centralrelation_t qt_meta_stringdata_V_Centralrelation = {
    {
QT_MOC_LITERAL(0, 0, 17) // "V_Centralrelation"

    },
    "V_Centralrelation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_V_Centralrelation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void V_Centralrelation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject V_Centralrelation::staticMetaObject = {
    { &V_CentralView::staticMetaObject, qt_meta_stringdata_V_Centralrelation.data,
      qt_meta_data_V_Centralrelation,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *V_Centralrelation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *V_Centralrelation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_V_Centralrelation.stringdata0))
        return static_cast<void*>(const_cast< V_Centralrelation*>(this));
    return V_CentralView::qt_metacast(_clname);
}

int V_Centralrelation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = V_CentralView::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_V_CentralCouple_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_V_CentralCouple_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_V_CentralCouple_t qt_meta_stringdata_V_CentralCouple = {
    {
QT_MOC_LITERAL(0, 0, 15) // "V_CentralCouple"

    },
    "V_CentralCouple"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_V_CentralCouple[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void V_CentralCouple::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject V_CentralCouple::staticMetaObject = {
    { &V_CentralView::staticMetaObject, qt_meta_stringdata_V_CentralCouple.data,
      qt_meta_data_V_CentralCouple,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *V_CentralCouple::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *V_CentralCouple::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_V_CentralCouple.stringdata0))
        return static_cast<void*>(const_cast< V_CentralCouple*>(this));
    return V_CentralView::qt_metacast(_clname);
}

int V_CentralCouple::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = V_CentralView::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
