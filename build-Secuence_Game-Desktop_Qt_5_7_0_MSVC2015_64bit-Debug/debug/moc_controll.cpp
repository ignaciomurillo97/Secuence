/****************************************************************************
** Meta object code from reading C++ file 'controll.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Secuence_Game/controll.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controll.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Controll_t {
    QByteArrayData data[10];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controll_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controll_t qt_meta_stringdata_Controll = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Controll"
QT_MOC_LITERAL(1, 9, 13), // "setTwoPlayers"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 15), // "setThreePlayers"
QT_MOC_LITERAL(4, 40, 14), // "setFourPlayers"
QT_MOC_LITERAL(5, 55, 18), // "choosePlayerScreen"
QT_MOC_LITERAL(6, 74, 10), // "nextPlayer"
QT_MOC_LITERAL(7, 85, 14), // "previousPlayer"
QT_MOC_LITERAL(8, 100, 14), // "undoLastAction"
QT_MOC_LITERAL(9, 115, 14) // "redoLastAction"

    },
    "Controll\0setTwoPlayers\0\0setThreePlayers\0"
    "setFourPlayers\0choosePlayerScreen\0"
    "nextPlayer\0previousPlayer\0undoLastAction\0"
    "redoLastAction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controll[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Controll::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controll *_t = static_cast<Controll *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setTwoPlayers(); break;
        case 1: _t->setThreePlayers(); break;
        case 2: _t->setFourPlayers(); break;
        case 3: _t->choosePlayerScreen(); break;
        case 4: _t->nextPlayer(); break;
        case 5: _t->previousPlayer(); break;
        case 6: _t->undoLastAction(); break;
        case 7: _t->redoLastAction(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Controll::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_Controll.data,
      qt_meta_data_Controll,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Controll::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controll::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Controll.stringdata0))
        return static_cast<void*>(const_cast< Controll*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int Controll::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
