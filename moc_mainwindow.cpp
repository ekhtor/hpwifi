/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Mar 26 13:15:31 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      39,   11,   11,   11, 0x08,
      65,   11,   11,   11, 0x08,
      91,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     143,   11,   11,   11, 0x08,
     169,   11,   11,   11, 0x08,
     195,   11,   11,   11, 0x08,
     224,   11,   11,   11, 0x08,
     255,  250,   11,   11, 0x08,
     301,   11,   11,   11, 0x08,
     327,   11,   11,   11, 0x08,
     357,  351,   11,   11, 0x08,
     396,   11,   11,   11, 0x08,
     431,   11,   11,   11, 0x08,
     464,   11,   11,   11, 0x08,
     503,  351,   11,   11, 0x08,
     532,  351,   11,   11, 0x08,
     563,   11,   11,   11, 0x08,
     598,   11,   11,   11, 0x08,
     629,  625,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_pushButton_10_clicked()\0"
    "on_pushButton_9_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_spinBox_valueChanged(int)\0"
    "on_pushButton_3_clicked()\0item\0"
    "on_tableWidget_itemClicked(QTableWidgetItem*)\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0index\0"
    "on_comboBox_2_currentIndexChanged(int)\0"
    "on_comboBox_2_textChanged(QString)\0"
    "on_comboBox_2_activated(QString)\0"
    "on_comboBox_2_editTextChanged(QString)\0"
    "on_comboBox_2_activated(int)\0"
    "on_comboBox_2_highlighted(int)\0"
    "on_comboBox_2_highlighted(QString)\0"
    "on_pushButton_11_clicked()\0arg\0"
    "start_routine(void*)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_10_clicked(); break;
        case 1: on_pushButton_9_clicked(); break;
        case 2: on_pushButton_8_clicked(); break;
        case 3: on_pushButton_7_clicked(); break;
        case 4: on_pushButton_6_clicked(); break;
        case 5: on_pushButton_5_clicked(); break;
        case 6: on_pushButton_4_clicked(); break;
        case 7: on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_pushButton_3_clicked(); break;
        case 9: on_tableWidget_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 10: on_pushButton_2_clicked(); break;
        case 11: on_pushButton_clicked(); break;

        case 19: on_pushButton_11_clicked(); break;
        case 20: start_routine((*reinterpret_cast< void*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
