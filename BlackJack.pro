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
    Functions.cpp

HEADERS  += mainwindow.h \
    Functions.h

FORMS    += mainwindow.ui

#enable console
CONFIG += console
