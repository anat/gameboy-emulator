QT += core

TEMPLATE = app
CONFIG += console
CONFIG += qt
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += ROM/ CPU/ GPU/

LIBS += -lsfml-system -lsfml-graphics -lsfml-window

SOURCES += main.cpp \
    ROM/ROMLoader.cpp \
    CPU/CPU.cpp \
    gameboy.cpp \
    Memory.cpp \
    GPU/GPU.cpp \
    CPU/Interruption.cpp \
    GPU/Sprite.cpp \
    GPU/Attribute.cpp \
    CPU/BitInstruction.cpp

HEADERS += \
    ROM/ROMLoader.h \
    ROM/ROMHeader.h \
    CPU/CPU.h \
    CPU/ALU.h \
    CPU/Register.h \
    CPU/Loads.h \
    CPU/Jumps.h \
    Memory.h \
    gameboy.h \
    macro.h \
    GPU/GPU.h \
    CPU/Interruption.h \
    GPU/Sprite.h \
    GPU/Attribute.h \
    CPU/BitInstruction.h

