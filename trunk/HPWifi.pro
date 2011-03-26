#-------------------------------------------------
#
# Project created by QtCreator 2011-01-27T15:43:04
#
#-------------------------------------------------

QT       += core gui

TARGET = HPWifi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    dialog2.cpp \
    mainwindow2.cpp \
    form.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    dialog2.h \
    mainwindow2.h \
    form.h

FORMS    += mainwindow.ui \
    dialog.ui \
    dialog2.ui \
    mainwindow2.ui \
    form.ui

LIBS += -L /usr/lib/libtinyxml.so -ltinyxml


