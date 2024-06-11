/****************************************************************************
** Meta object code from reading C++ file 'fisicas.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../fisicas.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fisicas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSfisicasENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSfisicasENDCLASS = QtMocHelpers::stringData(
    "fisicas",
    "parabolic_shoot",
    "",
    "parabolic_shoot_bomba",
    "MRU",
    "set_starting_parameters",
    "x",
    "y",
    "vx",
    "vy",
    "zigzag",
    "mover_bala",
    "bomba",
    "harmonic_motion",
    "pendulum_motion"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSfisicasENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[8];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[4];
    char stringdata5[24];
    char stringdata6[2];
    char stringdata7[2];
    char stringdata8[3];
    char stringdata9[3];
    char stringdata10[7];
    char stringdata11[11];
    char stringdata12[6];
    char stringdata13[16];
    char stringdata14[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSfisicasENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSfisicasENDCLASS_t qt_meta_stringdata_CLASSfisicasENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "fisicas"
        QT_MOC_LITERAL(8, 15),  // "parabolic_shoot"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 21),  // "parabolic_shoot_bomba"
        QT_MOC_LITERAL(47, 3),  // "MRU"
        QT_MOC_LITERAL(51, 23),  // "set_starting_parameters"
        QT_MOC_LITERAL(75, 1),  // "x"
        QT_MOC_LITERAL(77, 1),  // "y"
        QT_MOC_LITERAL(79, 2),  // "vx"
        QT_MOC_LITERAL(82, 2),  // "vy"
        QT_MOC_LITERAL(85, 6),  // "zigzag"
        QT_MOC_LITERAL(92, 10),  // "mover_bala"
        QT_MOC_LITERAL(103, 5),  // "bomba"
        QT_MOC_LITERAL(109, 15),  // "harmonic_motion"
        QT_MOC_LITERAL(125, 15)   // "pendulum_motion"
    },
    "fisicas",
    "parabolic_shoot",
    "",
    "parabolic_shoot_bomba",
    "MRU",
    "set_starting_parameters",
    "x",
    "y",
    "vx",
    "vy",
    "zigzag",
    "mover_bala",
    "bomba",
    "harmonic_motion",
    "pendulum_motion"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSfisicasENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    4,   71,    2, 0x08,    4 /* Private */,
      10,    0,   80,    2, 0x08,    9 /* Private */,
      11,    0,   81,    2, 0x08,   10 /* Private */,
      12,    0,   82,    2, 0x08,   11 /* Private */,
      13,    0,   83,    2, 0x08,   12 /* Private */,
      14,    0,   84,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject fisicas::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSfisicasENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSfisicasENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSfisicasENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<fisicas, std::true_type>,
        // method 'parabolic_shoot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'parabolic_shoot_bomba'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'MRU'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'set_starting_parameters'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'zigzag'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mover_bala'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'bomba'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'harmonic_motion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pendulum_motion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void fisicas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<fisicas *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->parabolic_shoot(); break;
        case 1: _t->parabolic_shoot_bomba(); break;
        case 2: _t->MRU(); break;
        case 3: _t->set_starting_parameters((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 4: _t->zigzag(); break;
        case 5: _t->mover_bala(); break;
        case 6: _t->bomba(); break;
        case 7: _t->harmonic_motion(); break;
        case 8: _t->pendulum_motion(); break;
        default: ;
        }
    }
}

const QMetaObject *fisicas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fisicas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSfisicasENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int fisicas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
