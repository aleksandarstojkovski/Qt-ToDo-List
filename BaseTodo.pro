#-------------------------------------------------
#
# Project created by QtCreator 2014-02-02T14:10:47
#
#-------------------------------------------------

QT       += widgets core gui sql

TARGET = BaseTodo
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    modellodati.cpp \
    sqlitebackend.cpp \
    todoelement.cpp \
    todoeditdialog.cpp

HEADERS  += mainwindow.h \
    modellodati.h \
    sqlitebackend.h \
    todoelement.h \
    todoeditdialog.h

FORMS    += mainwindow.ui \
    todoeditdialog.ui
