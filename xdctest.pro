# -------------------------------------------------
# xdc: test build config
# -------------------------------------------------

QT += network
QT += testlib
QT -= gui

TARGET = xdctest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app

# -------------------------------------------------
# all sources and headers from xdc main 
# build, except xdc/src/main.cpp
# -------------------------------------------------
SOURCES += xdc/src/hubconnection.cpp \
    xdc/src/xdcstartup.cpp \
    xdc/src/utils/dcutils.cpp \
    xdc/src/utils/dctokenparser.cpp \
    xdc/src/utils/rawstringutils.cpp \
    xdc/src/uiinterface/uiconnectionlistener.cpp \
    xdc/src/uiinterface/uiconnection.cpp \
    xdc/src/uiinterface/uiconnectionlist.cpp \
    xdc/src/uiinterface/uinotifier.cpp \
    xdc/src/uiinterface/uireader.cpp \
    xdc/src/uiinterface/uimessage.cpp \
    xdc/src/uiinterface/uinlsmessage.cpp
HEADERS += xdc/include/xdcstartup.h \
    xdc/include/hubconnection.h \
    xdc/include/utils/dcutils.h \
    xdc/include/utils/dctokenparser.h \
    xdc/include/utils/rawstringutils.h \
    xdc/include/uiinterface/uiconnectionlistener.h \
    xdc/include/uiinterface/uiconnection.h \
    xdc/include/uiinterface/uiconnectionlist.h \
    xdc/include/uiinterface/uinotifier.h \
    xdc/include/uiinterface/uireader.h \
    xdc/include/uiinterface/uimessage.h \
    xdc/include/uiinterface/uinlsmessage.h

INCLUDEPATH += xdc/include/

# -------------------------------------------------
# sources from the test tree
# -------------------------------------------------
SOURCES += test/src/main.cpp \
    test/src/uiinterface/uinlsmessagetest.cpp
HEADERS += test/include/uiinterface/uinlsmessagetest.h

INCLUDEPATH += test/include/

# -------------------------------------------------
# build paths
# -------------------------------------------------

OBJECTS_DIR = test/build/
MOC_DIR = test/build/moc/
DESTDIR = test/

