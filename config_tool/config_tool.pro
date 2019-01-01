#-------------------------------------------------
#
# Project created by QtCreator 2018-12-19T20:19:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = config_tool
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
        main.cpp \
        config_tool.cpp \
    comm/comm.cpp

HEADERS += \
        config_tool.h \
    comm/comm.h

FORMS += \
        config_tool.ui

LIBS += -lcoap-1
INCLUDEPATH += /usr/include/coap
DEPENDPATH +=  /usr/include/coap
QMAKE_CXXFLAGS += -O0 -g -D_GNU_SOURCE -DWITH_POSIX

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

