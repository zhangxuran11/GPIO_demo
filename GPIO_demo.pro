#-------------------------------------------------
#
# Project created by QtCreator 2015-09-19T13:57:52
#
#-------------------------------------------------

QT       += core gui

TARGET = GPIO_demo
TEMPLATE = app
include(GPIOPkg/GPIOPkg.pri)

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
DEFINES += $$(ARCH)
contains( DEFINES, arm ) {
    mytarget.commands = scp ./${TARGET} root@192.168.1.30:/
}
!contains( DEFINES, arm ) {
}
mytarget.target = a

mytarget.depends = all



QMAKE_EXTRA_TARGETS += mytarget
