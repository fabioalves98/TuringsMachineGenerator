/****************************************************************************
** Meta object code from reading C++ file 'editmachines.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TuringsMachineSimulator/editmachines.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editmachines.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditMachines_t {
    QByteArrayData data[7];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditMachines_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditMachines_t qt_meta_stringdata_EditMachines = {
    {
QT_MOC_LITERAL(0, 0, 12), // "EditMachines"
QT_MOC_LITERAL(1, 13, 24), // "on_tableView_cellClicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 3), // "row"
QT_MOC_LITERAL(4, 43, 6), // "column"
QT_MOC_LITERAL(5, 50, 20), // "on_changeBut_clicked"
QT_MOC_LITERAL(6, 71, 18) // "on_saveBut_clicked"

    },
    "EditMachines\0on_tableView_cellClicked\0"
    "\0row\0column\0on_changeBut_clicked\0"
    "on_saveBut_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditMachines[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x08 /* Private */,
       5,    0,   34,    2, 0x08 /* Private */,
       6,    0,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EditMachines::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditMachines *_t = static_cast<EditMachines *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tableView_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_changeBut_clicked(); break;
        case 2: _t->on_saveBut_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject EditMachines::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_EditMachines.data,
      qt_meta_data_EditMachines,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EditMachines::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditMachines::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditMachines.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int EditMachines::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE