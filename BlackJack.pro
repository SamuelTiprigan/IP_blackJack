#-------------------------------------------------
#
# Project created by QtCreator 2017-01-13T11:39:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BlackJack
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Functions.cpp \
    editprofile.cpp \
    BlackJack.cpp

HEADERS  += mainwindow.h \
    Functions.h \
    editprofile.h \
    BlackJack.h

FORMS    += mainwindow.ui \
    editprofile.ui

#enable console
CONFIG += console
