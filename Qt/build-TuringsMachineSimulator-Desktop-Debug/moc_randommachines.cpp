/****************************************************************************
** Meta object code from reading C++ file 'randommachines.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TuringsMachineSimulator/randommachines.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'randommachines.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RandomMachines_t {
    QByteArrayData data[11];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RandomMachines_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RandomMachines_t qt_meta_stringdata_RandomMachines = {
    {
QT_MOC_LITERAL(0, 0, 14), // "RandomMachines"
QT_MOC_LITERAL(1, 15, 21), // "on_stSel_valueChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 4), // "arg1"
QT_MOC_LITERAL(4, 43, 15), // "changeHorHeader"
QT_MOC_LITERAL(5, 59, 2), // "st"
QT_MOC_LITERAL(6, 62, 15), // "changeVerHeader"
QT_MOC_LITERAL(7, 78, 2), // "sy"
QT_MOC_LITERAL(8, 81, 21), // "on_sySel_valueChanged"
QT_MOC_LITERAL(9, 103, 18), // "on_randBut_clicked"
QT_MOC_LITERAL(10, 122, 18) // "on_saveBut_clicked"

    },
    "RandomMachines\0on_stSel_valueChanged\0"
    "\0arg1\0changeHorHeader\0st\0changeVerHeader\0"
    "sy\0on_sySel_valueChanged\0on_randBut_clicked\0"
    "on_saveBut_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RandomMachines[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       6,    1,   50,    2, 0x08 /* Private */,
       8,    1,   53,    2, 0x08 /* Private */,
       9,    0,   56,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RandomMachines::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RandomMachines *_t = static_cast<RandomMachines *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_stSel_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeHorHeader((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeVerHeader((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_sySel_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_randBut_clicked(); break;
        case 5: _t->on_saveBut_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject RandomMachines::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RandomMachines.data,
      qt_meta_data_RandomMachines,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RandomMachines::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RandomMachines::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RandomMachines.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int RandomMachines::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
