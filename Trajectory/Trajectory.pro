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
        mainwindow.cpp \
    change.cpp \
    area.cpp \
    trajectory.cpp \
    controlpanel.cpp \
    graftrajectory.cpp

HEADERS  += mainwindow.h \
    change.h \
    area.h \
    trajectory.h \
    controlpanel.h \
    graftrajectory.h

FORMS    += mainwindow.ui \
    change.ui \
    area.ui \
    trajectory.ui \
    controlpanel.ui \
    graftrajectory.ui

CONFIG += qwt

include ( /usr/local/qwt-6.1.2/features/qwt.prf )
include(/opt/embedded-widgets-1.1.0/src/svgbutton/svgbutton.pri)

RESOURCES += resourses.qrc

QT *= svg

