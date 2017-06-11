/****************************************************************************
** Meta object code from reading C++ file 'v_centralnote.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../plurinotes/views/v_centralnote.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'v_centralnote.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_V_CentralNote_t {
    QByteArrayData data[3];
    char stringdata0[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_V_CentralNote_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_V_CentralNote_t qt_meta_stringdata_V_CentralNote = {
    {
QT_MOC_LITERAL(0, 0, 13), // "V_CentralNote"
QT_MOC_LITERAL(1, 14, 10), // "deleteNote"
QT_MOC_LITERAL(2, 25, 0) // ""

    },
    "V_CentralNote\0deleteNote\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_V_CentralNote[] = {

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
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void V_CentralNote::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        V_CentralNote *_t = static_cast<V_CentralNote *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteNote(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject V_CentralNote::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_V_CentralNote.data,
      qt_meta_data_V_CentralNote,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *V_CentralNote::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *V_CentralNote::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_V_CentralNote.stringdata0))
        return static_cast<void*>(const_cast< V_CentralNote*>(this));
    return QWidget::qt_metacast(_clname);
}

int V_CentralNote::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_V_CentralArticle_t {
    QByteArrayData data[3];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_V_CentralArticle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_V_CentralArticle_t qt_meta_stringdata_V_CentralArticle = {
    {
QT_MOC_LITERAL(0, 0, 16), // "V_CentralArticle"
QT_MOC_LITERAL(1, 17, 11), // "editArticle"
QT_MOC_LITERAL(2, 29, 0) // ""

    },
    "V_CentralArticle\0editArticle\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_V_CentralArticle[] = {

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
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void V_CentralArticle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        V_CentralArticle *_t = static_cast<V_CentralArticle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->editArticle(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject V_CentralArticle::staticMetaObject = {
    { &V_CentralNote::staticMetaObject, qt_meta_stringdata_V_CentralArticle.data,
      qt_meta_data_V_CentralArticle,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *V_CentralArticle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *V_CentralArticle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_V_CentralArticle.stringdata0))
        return static_cast<void*>(const_cast< V_CentralArticle*>(this));
    return V_CentralNote::qt_metacast(_clname);
}

int V_CentralArticle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = V_CentralNote::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_V_CentralMultimedia_t {
    QByteArrayData data[4];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_V_CentralMultimedia_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_V_CentralMultimedia_t qt_meta_stringdata_V_CentralMultimedia = {
    {
QT_MOC_LITERAL(0, 0, 19), // "V_CentralMultimedia"
QT_MOC_LITERAL(1, 20, 14), // "editMultimedia"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11) // "Multimedia*"

    },
    "V_CentralMultimedia\0editMultimedia\0\0"
    "Multimedia*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_V_CentralMultimedia[] = {

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
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void V_CentralMultimedia::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        V_CentralMultimedia *_t = static_cast<V_CentralMultimedia *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->editMultimedia((*reinterpret_cast< Multimedia*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject V_CentralMultimedia::staticMetaObject = {
    { &V_CentralNote::staticMetaObject, qt_meta_stringdata_V_CentralMultimedia.data,
      qt_meta_data_V_CentralMultimedia,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *V_CentralMultimedia::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *V_CentralMultimedia::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_V_CentralMultimedia.stringdata0))
        return static_cast<void*>(const_cast< V_CentralMultimedia*>(this));
    return V_CentralNote::qt_metacast(_clname);
}

int V_CentralMultimedia::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = V_CentralNote::qt_metacall(_c, _id, _a);
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
