QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clase_base.cpp \
    enemies.cpp \
    escenario.cpp \
    fisicas.cpp \
    main.cpp \
    obstaculo.cpp \
    personaje.cpp \
    proyectil.cpp \
    sprites.cpp \
    ventana.cpp

HEADERS += \
    clase_base.h \
    enemies.h \
    escenario.h \
    fisicas.h \
    obstaculo.h \
    personaje.h \
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
    nivel1.qrc \
    obstaculo1.qrc
