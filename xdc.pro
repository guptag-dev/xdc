# -------------------------------------------------
# Project created by QtCreator 2009-09-09T12:11:46
# -------------------------------------------------
QT += network
QT -= gui
TARGET = xdc
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    hubconnection.cpp \
    utils/dcutils.cpp \
    utils/dctokenparser.cpp \
    utils/rawstringutils.cpp \
    uiinterface/uiconnectionlistener.cpp \
    uiinterface/uiconnection.cpp
HEADERS += hubconnection.h \
    utils/dcutils.h \
    utils/dctokenparser.h \
    utils/rawstringutils.h \
    uiinterface/uiconnectionlistener.h \
    uiinterface/uiconnection.h
