/****************************************************************************
** Meta object code from reading C++ file 'change.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Trajectory/change.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'change.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Change_t {
    QByteArrayData data[11];
    char stringdata[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Change_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Change_t qt_meta_stringdata_Change = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Change"
QT_MOC_LITERAL(1, 7, 11), // "pressButton"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "index"
QT_MOC_LITERAL(4, 26, 12), // "pressButton1"
QT_MOC_LITERAL(5, 39, 12), // "pressButton2"
QT_MOC_LITERAL(6, 52, 12), // "pressButton3"
QT_MOC_LITERAL(7, 65, 12), // "pressButton4"
QT_MOC_LITERAL(8, 78, 12), // "pressButton5"
QT_MOC_LITERAL(9, 91, 12), // "pressButton6"
QT_MOC_LITERAL(10, 104, 12) // "pressButton7"

    },
    "Change\0pressButton\0\0index\0pressButton1\0"
    "pressButton2\0pressButton3\0pressButton4\0"
    "pressButton5\0pressButton6\0pressButton7"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Change[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   57,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

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

void Change::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Change *_t = static_cast<Change *>(_o);
        switch (_id) {
        case 0: _t->pressButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->pressButton1(); break;
        case 2: _t->pressButton2(); break;
        case 3: _t->pressButton3(); break;
        case 4: _t->pressButton4(); break;
        case 5: _t->pressButton5(); break;
        case 6: _t->pressButton6(); break;
        case 7: _t->pressButton7(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Change::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Change::pressButton)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Change::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Change.data,
      qt_meta_data_Change,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Change::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Change::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Change.stringdata))
        return static_cast<void*>(const_cast< Change*>(this));
    return QWidget::qt_metacast(_clname);
}

int Change::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Change::pressButton(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
