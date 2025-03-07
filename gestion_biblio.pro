#-------------------------------------------------
#
# Project created by QtCreator 2022-04-28T12:57:08
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gestion_biblio
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    documents.cpp \
    book.cpp \
    journal.cpp \
    academicproj.cpp \
    library.cpp \
    signupdialog.cpp \
    gestdialog.cpp \
    admindialog.cpp \
    userdialog.cpp \
    account.cpp \
    admin.cpp \
    student.cpp \
    teacher.cpp

HEADERS  += mainwindow.h \
    documents.h \
    book.h \
    journal.h \
    academicproj.h \
    library.h \
    signupdialog.h \
    gestdialog.h \
    admindialog.h \
    userdialog.h \
    account.h \
    admin.h \
    student.h \
    teacher.h

FORMS    += mainwindow.ui \
    signupdialog.ui \
    gestdialog.ui \
    admindialog.ui \
    userdialog.ui
