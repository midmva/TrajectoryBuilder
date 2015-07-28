/****************************************************************************
** Meta object code from reading C++ file 'controlpanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Trajectory/controlpanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ControlPanel_t {
    QByteArrayData data[16];
    char stringdata[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControlPanel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControlPanel_t qt_meta_stringdata_ControlPanel = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ControlPanel"
QT_MOC_LITERAL(1, 13, 16), // "changeTrajectory"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 6), // "number"
QT_MOC_LITERAL(4, 38, 10), // "changeMode"
QT_MOC_LITERAL(5, 49, 4), // "mode"
QT_MOC_LITERAL(6, 54, 10), // "saveFileAs"
QT_MOC_LITERAL(7, 65, 4), // "name"
QT_MOC_LITERAL(8, 70, 12), // "loadFileFrom"
QT_MOC_LITERAL(9, 83, 12), // "pressButton1"
QT_MOC_LITERAL(10, 96, 12), // "pressButton2"
QT_MOC_LITERAL(11, 109, 12), // "pressButton3"
QT_MOC_LITERAL(12, 122, 12), // "pressButton4"
QT_MOC_LITERAL(13, 135, 15), // "pressButtonGraf"
QT_MOC_LITERAL(14, 151, 15), // "pressButtonSave"
QT_MOC_LITERAL(15, 167, 15) // "pressButtonLoad"

    },
    "ControlPanel\0changeTrajectory\0\0number\0"
    "changeMode\0mode\0saveFileAs\0name\0"
    "loadFileFrom\0pressButton1\0pressButton2\0"
    "pressButton3\0pressButton4\0pressButtonGraf\0"
    "pressButtonSave\0pressButtonLoad"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControlPanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,
       8,    1,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,
      14,    0,   86,    2, 0x08 /* Private */,
      15,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ControlPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ControlPanel *_t = static_cast<ControlPanel *>(_o);
        switch (_id) {
        case 0: _t->changeTrajectory((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->changeMode((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 2: _t->saveFileAs((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->loadFileFrom((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->pressButton1(); break;
        case 5: _t->pressButton2(); break;
        case 6: _t->pressButton3(); break;
        case 7: _t->pressButton4(); break;
        case 8: _t->pressButtonGraf(); break;
        case 9: _t->pressButtonSave(); break;
        case 10: _t->pressButtonLoad(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ControlPanel::*_t)(const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ControlPanel::changeTrajectory)) {
                *result = 0;
            }
        }
        {
            typedef void (ControlPanel::*_t)(const bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ControlPanel::changeMode)) {
                *result = 1;
            }
        }
        {
            typedef void (ControlPanel::*_t)(const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ControlPanel::saveFileAs)) {
                *result = 2;
            }
        }
        {
            typedef void (ControlPanel::*_t)(const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ControlPanel::loadFileFrom)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ControlPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ControlPanel.data,
      qt_meta_data_ControlPanel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ControlPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControlPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ControlPanel.stringdata))
        return static_cast<void*>(const_cast< ControlPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int ControlPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ControlPanel::changeTrajectory(const int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ControlPanel::changeMode(const bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ControlPanel::saveFileAs(const QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ControlPanel::loadFileFrom(const QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
