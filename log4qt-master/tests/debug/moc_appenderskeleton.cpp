/****************************************************************************
** Meta object code from reading C++ file 'appenderskeleton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/log4qt/appenderskeleton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appenderskeleton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Log4Qt__AppenderSkeleton_t {
    QByteArrayData data[5];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Log4Qt__AppenderSkeleton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Log4Qt__AppenderSkeleton_t qt_meta_stringdata_Log4Qt__AppenderSkeleton = {
    {
QT_MOC_LITERAL(0, 0, 24), // "Log4Qt::AppenderSkeleton"
QT_MOC_LITERAL(1, 25, 8), // "isActive"
QT_MOC_LITERAL(2, 34, 8), // "isClosed"
QT_MOC_LITERAL(3, 43, 9), // "threshold"
QT_MOC_LITERAL(4, 53, 5) // "Level"

    },
    "Log4Qt::AppenderSkeleton\0isActive\0"
    "isClosed\0threshold\0Level"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Log4Qt__AppenderSkeleton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       3,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Bool, 0x00095001,
       2, QMetaType::Bool, 0x00095001,
       3, 0x80000000 | 4, 0x0009510b,

       0        // eod
};

void Log4Qt::AppenderSkeleton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        AppenderSkeleton *_t = static_cast<AppenderSkeleton *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isActive(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isClosed(); break;
        case 2: *reinterpret_cast< Level*>(_v) = _t->threshold(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        AppenderSkeleton *_t = static_cast<AppenderSkeleton *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setThreshold(*reinterpret_cast< Level*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Log4Qt::AppenderSkeleton::staticMetaObject = {
    { &Appender::staticMetaObject, qt_meta_stringdata_Log4Qt__AppenderSkeleton.data,
      qt_meta_data_Log4Qt__AppenderSkeleton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Log4Qt::AppenderSkeleton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Log4Qt::AppenderSkeleton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Log4Qt__AppenderSkeleton.stringdata0))
        return static_cast<void*>(this);
    return Appender::qt_metacast(_clname);
}

int Log4Qt::AppenderSkeleton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Appender::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
