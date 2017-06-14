/****************************************************************************
** Meta object code from reading C++ file 'v_multimediaform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../plurinotes/views/v_multimediaform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'v_multimediaform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_V_MultimediaForm_t {
    QByteArrayData data[4];
    char stringdata[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_V_MultimediaForm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_V_MultimediaForm_t qt_meta_stringdata_V_MultimediaForm = {
    {
QT_MOC_LITERAL(0, 0, 16), // "V_MultimediaForm"
QT_MOC_LITERAL(1, 17, 11), // "checkFields"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8) // "openFile"

    },
    "V_MultimediaForm\0checkFields\0\0openFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_V_MultimediaForm[] = {

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

void V_MultimediaForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        V_MultimediaForm *_t = static_cast<V_MultimediaForm *>(_o);
        switch (_id) {
        case 0: _t->checkFields(); break;
        case 1: _t->openFile(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject V_MultimediaForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_V_MultimediaForm.data,
      qt_meta_data_V_MultimediaForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *V_MultimediaForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *V_MultimediaForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_V_MultimediaForm.stringdata))
        return static_cast<void*>(const_cast< V_MultimediaForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int V_MultimediaForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
