#-------------------------------------------------
#
# Project created by QtCreator 2014-09-16T17:36:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    carro.cpp \
    gasolina.cpp \
    mecanico.cpp \
    automatico.cpp

HEADERS  += mainwindow.h \
    carro.h \
    gasolina.h \
    mecanico.h \
    automatico.h

FORMS    += mainwindow.ui
