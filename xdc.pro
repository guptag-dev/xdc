# -------------------------------------------------
# Project created by QtCreator 2009-09-09T12:11:46
# -------------------------------------------------
QT += network
QT -= gui
TARGET = xdc
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += src/main.cpp \
    src/hubconnection.cpp \
    src/utils/dcutils.cpp \
    src/utils/dctokenparser.cpp \
    src/utils/rawstringutils.cpp \
    src/uiinterface/uiconnectionlistener.cpp \
    src/uiinterface/uiconnection.cpp \
    src/xdcstartup.cpp \
    src/uiinterface/uiconnectionlist.cpp \
    src/uiinterface/uinotifier.cpp \
    src/uiinterface/uireader.cpp \
    src/uiinterface/uimessage.cpp \
    src/uiinterface/uinlsmessage.cpp
HEADERS += src/hubconnection.h \
    src/utils/dcutils.h \
    src/utils/dctokenparser.h \
    src/utils/rawstringutils.h \
    src/uiinterface/uiconnectionlistener.h \
    src/uiinterface/uiconnection.h \
    src/xdcstartup.h \
    src/uiinterface/uiconnectionlist.h \
    src/uiinterface/uinotifier.h \
    src/uiinterface/uireader.h \
    src/uiinterface/uimessage.h \
    src/uiinterface/uinlsmessage.h
