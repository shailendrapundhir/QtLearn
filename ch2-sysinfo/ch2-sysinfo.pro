#-------------------------------------------------
#
# Project created by QtCreator 2017-12-27T18:03:13
#
#-------------------------------------------------

QT       += core gui
CONFIG   += C++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ch2-sysinfo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += /System/Library/Frameworks/Kernel.framework/Versions/A/Headers \
               /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    sysinfo.cpp \
    sysinfowidget.cpp



HEADERS += \
        mainwindow.h \
    sysinfo.h \
    sysinfowidget.h


windows{
    SOURCES += sysinfowindowsimpl.cpp
    HEADERS += sysinfowindowsimpl.h
}

linux{
    SOURCES += sysinfolinuximpl.cpp
    HEADERS += sysinfolinuximpl.h
}

macx{
    SOURCES += sysinfomacimpl.cpp
    HEADERS += sysinfomacimpl.h
}

FORMS += \
        mainwindow.ui
