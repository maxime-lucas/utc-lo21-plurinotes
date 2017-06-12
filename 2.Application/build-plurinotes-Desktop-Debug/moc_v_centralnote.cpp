/****************************************************************************
** Meta object code from reading C++ file 'v_centralnote.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../plurinotes/views/v_centralnote.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'v_centralnote.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_V_CentralNote[] = {

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

static const char qt_meta_stringdata_V_CentralNote[] = {
    "V_CentralNote\0\0deleteNote()\0editNote()\0"
};

void V_CentralNote::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        V_CentralNote *_t = static_cast<V_CentralNote *>(_o);
        switch (_id) {
        case 0: _t->deleteNote(); break;
        case 1: _t->editNote(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData V_CentralNote::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject V_CentralNote::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_V_CentralNote,
      qt_meta_data_V_CentralNote, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &V_CentralNote::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *V_CentralNote::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *V_CentralNote::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_V_CentralNote))
        return static_cast<void*>(const_cast< V_CentralNote*>(this));
    return QWidget::qt_metacast(_clname);
}

int V_CentralNote::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
static const uint qt_meta_data_V_CentralArticle[] = {

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

static const char qt_meta_stringdata_V_CentralArticle[] = {
    "V_CentralArticle\0"
};

void V_CentralArticle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData V_CentralArticle::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject V_CentralArticle::staticMetaObject = {
    { &V_CentralNote::staticMetaObject, qt_meta_stringdata_V_CentralArticle,
      qt_meta_data_V_CentralArticle, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &V_CentralArticle::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *V_CentralArticle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *V_CentralArticle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_V_CentralArticle))
        return static_cast<void*>(const_cast< V_CentralArticle*>(this));
    return V_CentralNote::qt_metacast(_clname);
}

int V_CentralArticle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = V_CentralNote::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_V_CentralMultimedia[] = {

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

static const char qt_meta_stringdata_V_CentralMultimedia[] = {
    "V_CentralMultimedia\0"
};

void V_CentralMultimedia::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData V_CentralMultimedia::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject V_CentralMultimedia::staticMetaObject = {
    { &V_CentralNote::staticMetaObject, qt_meta_stringdata_V_CentralMultimedia,
      qt_meta_data_V_CentralMultimedia, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &V_CentralMultimedia::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *V_CentralMultimedia::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *V_CentralMultimedia::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_V_CentralMultimedia))
        return static_cast<void*>(const_cast< V_CentralMultimedia*>(this));
    return V_CentralNote::qt_metacast(_clname);
}

int V_CentralMultimedia::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = V_CentralNote::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_V_CentralTask[] = {

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

static const char qt_meta_stringdata_V_CentralTask[] = {
    "V_CentralTask\0"
};

void V_CentralTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData V_CentralTask::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject V_CentralTask::staticMetaObject = {
    { &V_CentralNote::staticMetaObject, qt_meta_stringdata_V_CentralTask,
      qt_meta_data_V_CentralTask, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &V_CentralTask::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *V_CentralTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *V_CentralTask::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_V_CentralTask))
        return static_cast<void*>(const_cast< V_CentralTask*>(this));
    return V_CentralNote::qt_metacast(_clname);
}

int V_CentralTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = V_CentralNote::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
