/****************************************************************************
** Meta object code from reading C++ file 'v_mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../plurinotes/views/v_mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'v_mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_V_Mainwindow_t {
    QByteArrayData data[7];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_V_Mainwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_V_Mainwindow_t qt_meta_stringdata_V_Mainwindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "V_Mainwindow"
QT_MOC_LITERAL(1, 13, 14), // "openNewArticle"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 17), // "openNewMultimedia"
QT_MOC_LITERAL(4, 47, 11), // "openNewTask"
QT_MOC_LITERAL(5, 59, 18), // "refreshCentralNote"
QT_MOC_LITERAL(6, 78, 19) // "setEmptyCentralNote"

    },
    "V_Mainwindow\0openNewArticle\0\0"
    "openNewMultimedia\0openNewTask\0"
    "refreshCentralNote\0setEmptyCentralNote"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_V_Mainwindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void V_Mainwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        V_Mainwindow *_t = static_cast<V_Mainwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openNewArticle(); break;
        case 1: _t->openNewMultimedia(); break;
        case 2: _t->openNewTask(); break;
        case 3: _t->refreshCentralNote((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setEmptyCentralNote(); break;
        default: ;
        }
    }
}

const QMetaObject V_Mainwindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_V_Mainwindow.data,
      qt_meta_data_V_Mainwindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *V_Mainwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *V_Mainwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_V_Mainwindow.stringdata0))
        return static_cast<void*>(const_cast< V_Mainwindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int V_Mainwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
