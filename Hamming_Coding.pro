#-------------------------------------------------
#
# Project created by QtCreator 2016-10-19T09:34:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hamming_Coding
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    encode_to_hamming.cpp

HEADERS  += mainwindow.h \
    hamming_encoding.h

FORMS    += mainwindow.ui
