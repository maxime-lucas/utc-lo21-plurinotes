/****************************************************************************
** Meta object code from reading C++ file 'v_mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../plurinotes/views/v_mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'v_mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_V_Mainwindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      31,   13,   13,   13, 0x0a,
      51,   13,   13,   13, 0x0a,
      65,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_V_Mainwindow[] = {
    "V_Mainwindow\0\0openNewArticle()\0"
    "openNewMultimedia()\0openNewTask()\0"
    "refreshCentralNote(QString)\0"
};

void V_Mainwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        V_Mainwindow *_t = static_cast<V_Mainwindow *>(_o);
        switch (_id) {
        case 0: _t->openNewArticle(); break;
        case 1: _t->openNewMultimedia(); break;
        case 2: _t->openNewTask(); break;
        case 3: _t->refreshCentralNote((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData V_Mainwindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject V_Mainwindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_V_Mainwindow,
      qt_meta_data_V_Mainwindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &V_Mainwindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *V_Mainwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *V_Mainwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_V_Mainwindow))
        return static_cast<void*>(const_cast< V_Mainwindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int V_Mainwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
