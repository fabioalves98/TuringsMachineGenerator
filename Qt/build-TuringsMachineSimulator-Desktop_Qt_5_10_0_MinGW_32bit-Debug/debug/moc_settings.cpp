/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TuringsMachineSimulator/settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Settings_t {
    QByteArrayData data[20];
    char stringdata0[355];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Settings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Settings_t qt_meta_stringdata_Settings = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Settings"
QT_MOC_LITERAL(1, 9, 13), // "loadPresetSgn"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "Machine*"
QT_MOC_LITERAL(4, 33, 28), // "on_maxStSpinBox_valueChanged"
QT_MOC_LITERAL(5, 62, 4), // "arg1"
QT_MOC_LITERAL(6, 67, 28), // "on_minStSpinBox_valueChanged"
QT_MOC_LITERAL(7, 96, 26), // "on_rInStCheck_stateChanged"
QT_MOC_LITERAL(8, 123, 28), // "on_maxSySpinBox_valueChanged"
QT_MOC_LITERAL(9, 152, 28), // "on_minSySpinBox_valueChanged"
QT_MOC_LITERAL(10, 181, 28), // "on_haltSimCheck_stateChanged"
QT_MOC_LITERAL(11, 210, 9), // "fixStates"
QT_MOC_LITERAL(12, 220, 2), // "st"
QT_MOC_LITERAL(13, 223, 10), // "fixSymbols"
QT_MOC_LITERAL(14, 234, 2), // "sy"
QT_MOC_LITERAL(15, 237, 26), // "on_tapeSySBox_valueChanged"
QT_MOC_LITERAL(16, 264, 25), // "on_rBSyCheck_stateChanged"
QT_MOC_LITERAL(17, 290, 23), // "on_loadPresetBt_clicked"
QT_MOC_LITERAL(18, 314, 34), // "on_presetsCBox_currentIndexCh..."
QT_MOC_LITERAL(19, 349, 5) // "index"

    },
    "Settings\0loadPresetSgn\0\0Machine*\0"
    "on_maxStSpinBox_valueChanged\0arg1\0"
    "on_minStSpinBox_valueChanged\0"
    "on_rInStCheck_stateChanged\0"
    "on_maxSySpinBox_valueChanged\0"
    "on_minSySpinBox_valueChanged\0"
    "on_haltSimCheck_stateChanged\0fixStates\0"
    "st\0fixSymbols\0sy\0on_tapeSySBox_valueChanged\0"
    "on_rBSyCheck_stateChanged\0"
    "on_loadPresetBt_clicked\0"
    "on_presetsCBox_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Settings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   82,    2, 0x08 /* Private */,
       6,    1,   85,    2, 0x08 /* Private */,
       7,    1,   88,    2, 0x08 /* Private */,
       8,    1,   91,    2, 0x08 /* Private */,
       9,    1,   94,    2, 0x08 /* Private */,
      10,    1,   97,    2, 0x08 /* Private */,
      11,    1,  100,    2, 0x08 /* Private */,
      13,    1,  103,    2, 0x08 /* Private */,
      15,    1,  106,    2, 0x08 /* Private */,
      16,    1,  109,    2, 0x08 /* Private */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    1,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Int, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,

       0        // eod
};

void Settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Settings *_t = static_cast<Settings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->loadPresetSgn((*reinterpret_cast< Machine*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->on_maxStSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_minStSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_rInStCheck_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_maxSySpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_minSySpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_haltSimCheck_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->fixStates((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->fixSymbols((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_tapeSySBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_rBSyCheck_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_loadPresetBt_clicked(); break;
        case 12: _t->on_presetsCBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef int (Settings::*_t)(Machine * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::loadPresetSgn)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Settings::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Settings.data,
      qt_meta_data_Settings,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Settings.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
int Settings::loadPresetSgn(Machine * _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
