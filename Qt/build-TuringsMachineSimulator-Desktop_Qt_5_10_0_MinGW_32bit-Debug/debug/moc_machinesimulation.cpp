/****************************************************************************
** Meta object code from reading C++ file 'machinesimulation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TuringsMachineSimulator/machinesimulation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'machinesimulation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MachineSimulation_t {
    QByteArrayData data[18];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MachineSimulation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MachineSimulation_t qt_meta_stringdata_MachineSimulation = {
    {
QT_MOC_LITERAL(0, 0, 17), // "MachineSimulation"
QT_MOC_LITERAL(1, 18, 18), // "selectTableCellSgn"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 14), // "insertStateSgn"
QT_MOC_LITERAL(4, 53, 13), // "insertTapeSgn"
QT_MOC_LITERAL(5, 67, 15), // "changeStatusSgn"
QT_MOC_LITERAL(6, 83, 11), // "resizeTable"
QT_MOC_LITERAL(7, 95, 18), // "selectTableCellSlt"
QT_MOC_LITERAL(8, 114, 2), // "st"
QT_MOC_LITERAL(9, 117, 2), // "sy"
QT_MOC_LITERAL(10, 120, 14), // "insertStateSlt"
QT_MOC_LITERAL(11, 135, 5), // "state"
QT_MOC_LITERAL(12, 141, 13), // "insertTapeSlt"
QT_MOC_LITERAL(13, 155, 4), // "tape"
QT_MOC_LITERAL(14, 160, 15), // "changeStatusSlt"
QT_MOC_LITERAL(15, 176, 6), // "status"
QT_MOC_LITERAL(16, 183, 23), // "on_headPos_valueChanged"
QT_MOC_LITERAL(17, 207, 4) // "arg1"

    },
    "MachineSimulation\0selectTableCellSgn\0"
    "\0insertStateSgn\0insertTapeSgn\0"
    "changeStatusSgn\0resizeTable\0"
    "selectTableCellSlt\0st\0sy\0insertStateSlt\0"
    "state\0insertTapeSlt\0tape\0changeStatusSlt\0"
    "status\0on_headPos_valueChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MachineSimulation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       3,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       5,    1,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   78,    2, 0x0a /* Public */,
       7,    2,   79,    2, 0x08 /* Private */,
      10,    1,   84,    2, 0x08 /* Private */,
      12,    1,   87,    2, 0x08 /* Private */,
      14,    1,   90,    2, 0x08 /* Private */,
      16,    1,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void MachineSimulation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MachineSimulation *_t = static_cast<MachineSimulation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectTableCellSgn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->insertStateSgn((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->insertTapeSgn((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->changeStatusSgn((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->resizeTable(); break;
        case 5: _t->selectTableCellSlt((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->insertStateSlt((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->insertTapeSlt((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->changeStatusSlt((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->on_headPos_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MachineSimulation::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MachineSimulation::selectTableCellSgn)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MachineSimulation::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MachineSimulation::insertStateSgn)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MachineSimulation::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MachineSimulation::insertTapeSgn)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MachineSimulation::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MachineSimulation::changeStatusSgn)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MachineSimulation::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MachineSimulation.data,
      qt_meta_data_MachineSimulation,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MachineSimulation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MachineSimulation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MachineSimulation.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MachineSimulation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MachineSimulation::selectTableCellSgn(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MachineSimulation::insertStateSgn(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MachineSimulation::insertTapeSgn(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MachineSimulation::changeStatusSgn(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
