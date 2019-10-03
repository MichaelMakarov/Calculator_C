#-------------------------------------------------
#
# Project created by QtCreator 2019-06-28T20:03:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    counter.cpp
        C:/Qt/Qt5.2.1/Tools/QtCreator/bin/UserLibrary/build-AdditionalFunctions-Desktop_Qt_5_2_1_MinGW_32bit-Debug/debug/libAdditionalFunctions.a

HEADERS  += mainwindow.h \
    counter.h
HEADERS += additionalfunctions.h

FORMS    += mainwindow.ui

INCLUDEPATH += "C:/Qt/Qt5.2.1/Tools/QtCreator/bin/UserLibrary/AdditionalFunctions/"
LIBS += -LC:/Qt/Qt5.2.1/Tools/QtCreator/bin/UserLibrary/build-AdditionalFunctions-Desktop_Qt_5_2_1_MinGW_32bit-Debug/debug/ -lAdditionalFunctions

RESOURCES += \
    splash_screen.qrc
