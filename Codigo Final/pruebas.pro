QT += core gui

greaterThan(QT_MAJOR_VERSION, 5):
QT += widgets
QT += core gui xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    event.cpp \
    main.cpp \
    objeto.cpp \
    piedra.cpp \
    platano.cpp \
    score.cpp \
    sprite.cpp \
    uva.cpp \
    widget.cpp

HEADERS += \
    event.h \
    objeto.h \
    piedra.h \
    platano.h \
    score.h \
    sprite.h \
    uva.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Imagenes/Imagenes.qrc

DISTFILES +=
