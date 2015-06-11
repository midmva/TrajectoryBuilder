#-------------------------------------------------
#
# Project created by QtCreator 2015-06-11T11:42:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Trajectory
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += qwt

include ( /usr/local/qwt-6.1.2/features/qwt.prf )
