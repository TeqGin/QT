#-------------------------------------------------
#
# Project created by QtCreator 2019-11-17T16:03:43
#
#-------------------------------------------------

QT       += core gui
QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        addorchangeroom.cpp \
        changeroomdata.cpp \
        chargeface.cpp \
        charger.cpp \
        date.cpp \
        db_connect.cpp \
        dialog.cpp \
        guests.cpp \
        loginface.cpp \
        main.cpp \
        mainwindow.cpp \
        operata.cpp \
        person.cpp \
        record.cpp \
        recordsql.cpp \
        room.cpp \
        roomdata.cpp \
        roomsql.cpp \
        typesql.cpp \
        usersql.cpp \
        whole.cpp

HEADERS += \
        addorchangeroom.h \
        changeroomdata.h \
        chargeface.h \
        charger.h \
        date.h \
        db_connect.h \
        dialog.h \
        domain.h \
        guests.h \
        loginface.h \
        mainwindow.h \
        operata.h \
        person.h \
        record.h \
        recordsql.h \
        room.h \
        roomdata.h \
        roomsql.h \
        sql.h \
        typesql.h \
        usersql.h \
        whole.h

FORMS += \
        addorchangeroom.ui \
        changeroomdata.ui \
        chargeface.ui \
        dialog.ui \
        loginface.ui \
        mainwindow.ui \
        roomdata.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
