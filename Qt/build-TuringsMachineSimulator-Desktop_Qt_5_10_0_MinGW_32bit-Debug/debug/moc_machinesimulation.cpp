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
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MachineSimulation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MachineSimulation_t qt_meta_stringdata_MachineSimulation = {
    {
QT_MOC_LITERAL(0, 0, 17), // "MachineSimulation"
QT_MOC_LITERAL(1, 18, 11), // "updateUiSgn"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 15), // "changeStatusSgn"
QT_MOC_LITERAL(4, 47, 15), // "delayChangedSgn"
QT_MOC_LITERAL(5, 63, 11), // "resizeTable"
QT_MOC_LITERAL(6, 75, 11), // "updateUiSlt"
QT_MOC_LITERAL(7, 87, 4), // "iter"
QT_MOC_LITERAL(8, 92, 2), // "st"
QT_MOC_LITERAL(9, 95, 2), // "sy"
QT_MOC_LITERAL(10, 98, 5), // "state"
QT_MOC_LITERAL(11, 104, 4), // "tape"
QT_MOC_LITERAL(12, 109, 6), // "status"
QT_MOC_LITERAL(13, 116, 15), // "changeStatusSlt"
QT_MOC_LITERAL(14, 132, 14), // "updateDelaySlt"
QT_MOC_LITERAL(15, 147, 5), // "delay"
QT_MOC_LITERAL(16, 153, 23), // "on_headPos_valueChanged"
QT_MOC_LITERAL(17, 177, 4) // "arg1"

    },
    "MachineSimulation\0updateUiSgn\0\0"
    "changeStatusSgn\0delayChangedSgn\0"
    "resizeTable\0updateUiSlt\0iter\0st\0sy\0"
    "state\0tape\0status\0changeStatusSlt\0"
    "updateDelaySlt\0delay\0on_headPos_valueChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MachineSimulation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   54,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,
       4,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   73,    2, 0x0a /* Public */,
       6,    6,   74,    2, 0x08 /* Private */,
      13,    1,   87,    2, 0x08 /* Private */,
      14,    1,   90,    2, 0x08 /* Private */,
      16,    1,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void MachineSimulation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MachineSimulation *_t = static_cast<MachineSimulation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateUiSgn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 1: _t->changeStatusSgn((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->delayChangedSgn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->resizeTable(); break;
        case 4: _t->updateUiSlt((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 5: _t->changeStatusSlt((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->updateDelaySlt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_headPos_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MachineSimulation::*_t)(int , int , int , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MachineSimulation::updateUiSgn)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MachineSimulation::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MachineSimulation::changeStatusSgn)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MachineSimulation::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MachineSimulation::delayChangedSgn)) {
                *result = 2;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MachineSimulation::updateUiSgn(int _t1, int _t2, int _t3, QString _t4, QString _t5, QString _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MachineSimulation::changeStatusSgn(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MachineSimulation::delayChangedSgn(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
