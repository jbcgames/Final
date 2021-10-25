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
    comiendo.cpp \
    event.cpp \
    explosion.cpp \
    main.cpp \
    manzana.cpp \
    nivel.cpp \
    nivelimg.cpp \
    objeto.cpp \
    piedra.cpp \
    piedramov.cpp \
    piedramovpend.cpp \
    piedramovsen.cpp \
    platano.cpp \
    rect.cpp \
    score.cpp \
    sprite.cpp \
    uva.cpp \
    widget.cpp

HEADERS += \
    comiendo.h \
    event.h \
    explosion.h \
    manzana.h \
    nivel.h \
    nivelimg.h \
    objeto.h \
    piedra.h \
    piedramov.h \
    piedramovpend.h \
    piedramovsen.h \
    platano.h \
    rect.h \
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
