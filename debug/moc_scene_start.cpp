/****************************************************************************
** Meta object code from reading C++ file 'scene_start.h'
**
** Created: Wed Mar 14 16:33:17 2018
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scene_start.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scene_start.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Scene_start[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

       0        // eod
};

static const char qt_meta_stringdata_Scene_start[] = {
    "Scene_start\0"
};

const QMetaObject Scene_start::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_Scene_start,
      qt_meta_data_Scene_start, 0 }
};

const QMetaObject *Scene_start::metaObject() const
{
    return &staticMetaObject;
}

void *Scene_start::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Scene_start))
        return static_cast<void*>(const_cast< Scene_start*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int Scene_start::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
