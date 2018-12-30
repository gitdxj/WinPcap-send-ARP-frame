/****************************************************************************
** Meta object code from reading C++ file 'na_qt_test2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../na_qt_test2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'na_qt_test2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NA_Qt_test2_t {
    QByteArrayData data[10];
    char stringdata[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NA_Qt_test2_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NA_Qt_test2_t qt_meta_stringdata_NA_Qt_test2 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NA_Qt_test2"
QT_MOC_LITERAL(1, 12, 11), // "onGetPacket"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 47, 8), // "onGetMAC"
QT_MOC_LITERAL(5, 56, 8), // "setDesIp"
QT_MOC_LITERAL(6, 65, 11), // "std::string"
QT_MOC_LITERAL(7, 77, 5), // "desIp"
QT_MOC_LITERAL(8, 83, 8), // "setSrcIp"
QT_MOC_LITERAL(9, 92, 5) // "srcIp"

    },
    "NA_Qt_test2\0onGetPacket\0\0on_pushButton_clicked\0"
    "onGetMAC\0setDesIp\0std::string\0desIp\0"
    "setSrcIp\0srcIp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NA_Qt_test2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       3,    0,   42,    2, 0x0a /* Public */,
       4,    1,   43,    2, 0x0a /* Public */,
       5,    1,   46,    2, 0x0a /* Public */,
       8,    1,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    9,

       0        // eod
};

void NA_Qt_test2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NA_Qt_test2 *_t = static_cast<NA_Qt_test2 *>(_o);
        switch (_id) {
        case 0: _t->onGetPacket((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->onGetMAC((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setDesIp((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: _t->setSrcIp((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject NA_Qt_test2::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_NA_Qt_test2.data,
      qt_meta_data_NA_Qt_test2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NA_Qt_test2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NA_Qt_test2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NA_Qt_test2.stringdata))
        return static_cast<void*>(const_cast< NA_Qt_test2*>(this));
    if (!strcmp(_clname, "Ui_NA_Qt_test2Class"))
        return static_cast< Ui_NA_Qt_test2Class*>(const_cast< NA_Qt_test2*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int NA_Qt_test2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
