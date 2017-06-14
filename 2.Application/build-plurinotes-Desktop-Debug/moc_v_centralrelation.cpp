/****************************************************************************
** Meta object code from reading C++ file 'v_centralrelation.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../plurinotes/views/v_centralrelation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'v_centralrelation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_V_CentralView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      28,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_V_CentralView[] = {
    "V_CentralView\0\0deleteView()\0editView()\0"
};

void V_CentralView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        V_CentralView *_t = static_cast<V_CentralView *>(_o);
        switch (_id) {
        case 0: _t->deleteView(); break;
        case 1: _t->editView(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData V_CentralView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject V_CentralView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_V_CentralView,
      qt_meta_data_V_CentralView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &V_CentralView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *V_CentralView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *V_CentralView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_V_CentralView))
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
    }
    return _id;
}
static const uint qt_meta_data_V_Centralrelation[] = {

 // content:
       6,       // revision
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

static const char qt_meta_stringdata_V_Centralrelation[] = {
    "V_Centralrelation\0"
};

void V_Centralrelation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData V_Centralrelation::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject V_Centralrelation::staticMetaObject = {
    { &V_CentralView::staticMetaObject, qt_meta_stringdata_V_Centralrelation,
      qt_meta_data_V_Centralrelation, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &V_Centralrelation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *V_Centralrelation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *V_Centralrelation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_V_Centralrelation))
        return static_cast<void*>(const_cast< V_Centralrelation*>(this));
    return V_CentralView::qt_metacast(_clname);
}

int V_Centralrelation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = V_CentralView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_V_CentralCouple[] = {

 // content:
       6,       // revision
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

static const char qt_meta_stringdata_V_CentralCouple[] = {
    "V_CentralCouple\0"
};

void V_CentralCouple::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData V_CentralCouple::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject V_CentralCouple::staticMetaObject = {
    { &V_CentralView::staticMetaObject, qt_meta_stringdata_V_CentralCouple,
      qt_meta_data_V_CentralCouple, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &V_CentralCouple::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *V_CentralCouple::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *V_CentralCouple::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_V_CentralCouple))
        return static_cast<void*>(const_cast< V_CentralCouple*>(this));
    return V_CentralView::qt_metacast(_clname);
}

int V_CentralCouple::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = V_CentralView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
