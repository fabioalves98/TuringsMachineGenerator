/****************************************************************************
** Meta object code from reading C++ file 'edittapes.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TuringsMachineSimulator/edittapes.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edittapes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditTapes_t {
    QByteArrayData data[10];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditTapes_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditTapes_t qt_meta_stringdata_EditTapes = {
    {
QT_MOC_LITERAL(0, 0, 9), // "EditTapes"
QT_MOC_LITERAL(1, 10, 21), // "on_plusLeftBt_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 22), // "on_minusLeftBt_clicked"
QT_MOC_LITERAL(4, 56, 23), // "on_minusRightBt_clicked"
QT_MOC_LITERAL(5, 80, 22), // "on_plusRightBt_clicked"
QT_MOC_LITERAL(6, 103, 29), // "on_blanckSymLEdit_textChanged"
QT_MOC_LITERAL(7, 133, 4), // "arg1"
QT_MOC_LITERAL(8, 138, 17), // "on_saveBt_clicked"
QT_MOC_LITERAL(9, 156, 20) // "on_restoreBt_clicked"

    },
    "EditTapes\0on_plusLeftBt_clicked\0\0"
    "on_minusLeftBt_clicked\0on_minusRightBt_clicked\0"
    "on_plusRightBt_clicked\0"
    "on_blanckSymLEdit_textChanged\0arg1\0"
    "on_saveBt_clicked\0on_restoreBt_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditTapes[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EditTapes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditTapes *_t = static_cast<EditTapes *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_plusLeftBt_clicked(); break;
        case 1: _t->on_minusLeftBt_clicked(); break;
        case 2: _t->on_minusRightBt_clicked(); break;
        case 3: _t->on_plusRightBt_clicked(); break;
        case 4: _t->on_blanckSymLEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_saveBt_clicked(); break;
        case 6: _t->on_restoreBt_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject EditTapes::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_EditTapes.data,
      qt_meta_data_EditTapes,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EditTapes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditTapes::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditTapes.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int EditTapes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
