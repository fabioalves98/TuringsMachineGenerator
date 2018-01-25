/****************************************************************************
** Meta object code from reading C++ file 'usermachines.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TuringsMachineSimulator/usermachines.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usermachines.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserMachines_t {
    QByteArrayData data[19];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserMachines_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserMachines_t qt_meta_stringdata_UserMachines = {
    {
QT_MOC_LITERAL(0, 0, 12), // "UserMachines"
QT_MOC_LITERAL(1, 13, 21), // "on_addTableBt_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "on_simBt_clicked"
QT_MOC_LITERAL(4, 53, 20), // "on_uselAllBt_clicked"
QT_MOC_LITERAL(5, 74, 19), // "on_selAllBt_clicked"
QT_MOC_LITERAL(6, 94, 9), // "finishSim"
QT_MOC_LITERAL(7, 104, 9), // "tableName"
QT_MOC_LITERAL(8, 114, 15), // "getMachToDispay"
QT_MOC_LITERAL(9, 130, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(10, 147, 4), // "item"
QT_MOC_LITERAL(11, 152, 17), // "on_stopBt_clicked"
QT_MOC_LITERAL(12, 170, 18), // "on_pauseBt_clicked"
QT_MOC_LITERAL(13, 189, 17), // "on_contBt_clicked"
QT_MOC_LITERAL(14, 207, 23), // "on_cRandTableBt_clicked"
QT_MOC_LITERAL(15, 231, 22), // "on_editTableBt_clicked"
QT_MOC_LITERAL(16, 254, 23), // "on_qRandTableBt_clicked"
QT_MOC_LITERAL(17, 278, 20), // "on_addTapeBt_clicked"
QT_MOC_LITERAL(18, 299, 11) // "tapeButtons"

    },
    "UserMachines\0on_addTableBt_clicked\0\0"
    "on_simBt_clicked\0on_uselAllBt_clicked\0"
    "on_selAllBt_clicked\0finishSim\0tableName\0"
    "getMachToDispay\0QListWidgetItem*\0item\0"
    "on_stopBt_clicked\0on_pauseBt_clicked\0"
    "on_contBt_clicked\0on_cRandTableBt_clicked\0"
    "on_editTableBt_clicked\0on_qRandTableBt_clicked\0"
    "on_addTapeBt_clicked\0tapeButtons"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserMachines[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       8,    1,   91,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,
      17,    0,  100,    2, 0x08 /* Private */,
      18,    1,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void UserMachines::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserMachines *_t = static_cast<UserMachines *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_addTableBt_clicked(); break;
        case 1: _t->on_simBt_clicked(); break;
        case 2: _t->on_uselAllBt_clicked(); break;
        case 3: _t->on_selAllBt_clicked(); break;
        case 4: _t->finishSim((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->getMachToDispay((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->on_stopBt_clicked(); break;
        case 7: _t->on_pauseBt_clicked(); break;
        case 8: _t->on_contBt_clicked(); break;
        case 9: _t->on_cRandTableBt_clicked(); break;
        case 10: _t->on_editTableBt_clicked(); break;
        case 11: _t->on_qRandTableBt_clicked(); break;
        case 12: _t->on_addTapeBt_clicked(); break;
        case 13: _t->tapeButtons((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject UserMachines::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UserMachines.data,
      qt_meta_data_UserMachines,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UserMachines::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserMachines::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserMachines.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int UserMachines::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
