#-------------------------------------------------
#
# Project created by QtCreator 2014-04-20T13:22:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = program
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    intervalarithmetic.cpp \
    functions.cpp \
    switchexception.cpp

HEADERS  += mainwindow.h \
    intervalarithmetic.h \
    functions.h \
    switchexception.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/x86_64-linux-gnu/release/ -lmpfr
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/x86_64-linux-gnu/debug/ -lmpfr
else:unix: LIBS += -L$$PWD/../../../../../../../usr/lib/x86_64-linux-gnu/ -lmpfr

INCLUDEPATH += $$PWD/../../../../../../../usr/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../../../../usr/lib/x86_64-linux-gnu
