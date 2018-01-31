/****************************************************************************
** Meta object code from reading C++ file 'randomtapes.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TuringsMachineSimulator/randomtapes.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'randomtapes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RandomTapes_t {
    QByteArrayData data[7];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RandomTapes_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RandomTapes_t qt_meta_stringdata_RandomTapes = {
    {
QT_MOC_LITERAL(0, 0, 11), // "RandomTapes"
QT_MOC_LITERAL(1, 12, 23), // "on_symSBox_valueChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 4), // "arg1"
QT_MOC_LITERAL(4, 42, 24), // "on_sizeSBox_valueChanged"
QT_MOC_LITERAL(5, 67, 17), // "on_randBt_clicked"
QT_MOC_LITERAL(6, 85, 17) // "on_saveBt_clicked"

    },
    "RandomTapes\0on_symSBox_valueChanged\0"
    "\0arg1\0on_sizeSBox_valueChanged\0"
    "on_randBt_clicked\0on_saveBt_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RandomTapes[] = {

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
       1,    1,   34,    2, 0x08 /* Private */,
       4,    1,   37,    2, 0x08 /* Private */,
       5,    0,   40,    2, 0x08 /* Private */,
       6,    0,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RandomTapes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RandomTapes *_t = static_cast<RandomTapes *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_symSBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_sizeSBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_randBt_clicked(); break;
        case 3: _t->on_saveBt_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject RandomTapes::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RandomTapes.data,
      qt_meta_data_RandomTapes,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RandomTapes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RandomTapes::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RandomTapes.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int RandomTapes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
