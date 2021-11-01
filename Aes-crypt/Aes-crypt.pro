TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Aes/AesCBC128.cpp \
        Aes/AesCBC192.cpp \
        Aes/AesCBC256.cpp \
        Aes/AesECB128.cpp \
        Aes/AesECB192.cpp \
        Aes/AesECB256.cpp \
        main.cpp

HEADERS += \
    Aes/AesCBC128.h \
    Aes/AesCBC192.h \
    Aes/AesCBC256.h \
    Aes/AesECB128.h \
    Aes/AesECB192.h \
    Aes/AesECB256.h \
    Aes/_private/AesDeclarations.h \
    Hex.h
