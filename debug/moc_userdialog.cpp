/****************************************************************************
** Meta object code from reading C++ file 'userdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../userdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserDialog_t {
    QByteArrayData data[13];
    char stringdata[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UserDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UserDialog_t qt_meta_stringdata_UserDialog = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 23),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 24),
QT_MOC_LITERAL(4, 61, 24),
QT_MOC_LITERAL(5, 86, 24),
QT_MOC_LITERAL(6, 111, 24),
QT_MOC_LITERAL(7, 136, 24),
QT_MOC_LITERAL(8, 161, 5),
QT_MOC_LITERAL(9, 167, 28),
QT_MOC_LITERAL(10, 196, 24),
QT_MOC_LITERAL(11, 221, 24),
QT_MOC_LITERAL(12, 246, 21)
    },
    "UserDialog\0on_Search_doc_2_clicked\0\0"
    "on_pushButton_18_clicked\0"
    "on_pushButton_15_clicked\0"
    "on_pushButton_16_clicked\0"
    "on_pushButton_17_clicked\0"
    "on_tableView_3_activated\0index\0"
    "on_tableView_his_4_activated\0"
    "on_pushButton_23_clicked\0"
    "on_pushButton_22_clicked\0on_pushButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08,
       3,    0,   65,    2, 0x08,
       4,    0,   66,    2, 0x08,
       5,    0,   67,    2, 0x08,
       6,    0,   68,    2, 0x08,
       7,    1,   69,    2, 0x08,
       9,    1,   72,    2, 0x08,
      10,    0,   75,    2, 0x08,
      11,    0,   76,    2, 0x08,
      12,    0,   77,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserDialog *_t = static_cast<UserDialog *>(_o);
        switch (_id) {
        case 0: _t->on_Search_doc_2_clicked(); break;
        case 1: _t->on_pushButton_18_clicked(); break;
        case 2: _t->on_pushButton_15_clicked(); break;
        case 3: _t->on_pushButton_16_clicked(); break;
        case 4: _t->on_pushButton_17_clicked(); break;
        case 5: _t->on_tableView_3_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_tableView_his_4_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_23_clicked(); break;
        case 8: _t->on_pushButton_22_clicked(); break;
        case 9: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject UserDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UserDialog.data,
      qt_meta_data_UserDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *UserDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UserDialog.stringdata))
        return static_cast<void*>(const_cast< UserDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int UserDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
