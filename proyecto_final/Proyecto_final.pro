QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arma.cpp \
    bombas.cpp \
    clase_base.cpp \
    enemies.cpp \
    escenario.cpp \
    fisicas.cpp \
    main.cpp \
    nivel2.cpp \
    nuclearbombs.cpp \
    personaje.cpp \
    plano.cpp \
    proyectil.cpp \
    sprites.cpp \
    ventana.cpp

HEADERS += \
    arma.h \
    bombas.h \
    clase_base.h \
    enemies.h \
    escenario.h \
    fisicas.h \
    nivel2.h \
    nuclearbombs.h \
    personaje.h \
    plano.h \
    proyectil.h \
    sprites.h \
    ventana.h

FORMS += \
    ventana.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    nivel1.qrc
