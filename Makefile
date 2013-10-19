#############################################################################
# Makefile for building: GameBoy
# Generated by qmake (2.01a) (Qt 4.7.4) on: Mon Oct 7 02:24:10 2013
# Project:  GameBoy.pro
# Template: app
# Command: /home/anat/QtSDK/Desktop/Qt/474/gcc/bin/qmake -spec ../QtSDK/Desktop/Qt/474/gcc/mkspecs/linux-g++ CONFIG+=debug -o Makefile GameBoy.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -g -D_REENTRANT -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -g -D_REENTRANT -Wall -W $(DEFINES)
INCPATH       = -I../QtSDK/Desktop/Qt/474/gcc/mkspecs/linux-g++ -I. -I../QtSDK/Desktop/Qt/474/gcc/include/QtCore -I../QtSDK/Desktop/Qt/474/gcc/include/QtGui -I../QtSDK/Desktop/Qt/474/gcc/include -IROM -ICPU -IGPU -I.
LINK          = g++
LFLAGS        = -Wl,-rpath,/home/anat/QtSDK/Desktop/Qt/474/gcc/lib
LIBS          = $(SUBLIBS)  -L/home/anat/QtSDK/Desktop/Qt/474/gcc/lib -lsfml-system -lsfml-graphics -lsfml-window -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/anat/QtSDK/Desktop/Qt/474/gcc/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		ROM/ROMLoader.cpp \
		CPU/CPU.cpp \
		gameboy.cpp \
		Memory.cpp \
		GPU/GPU.cpp \
		CPU/Interruption.cpp \
		GPU/Sprite.cpp \
		GPU/Attribute.cpp \
		CPU/BitInstruction.cpp 
OBJECTS       = main.o \
		ROMLoader.o \
		CPU.o \
		gameboy.o \
		Memory.o \
		GPU.o \
		Interruption.o \
		Sprite.o \
		Attribute.o \
		BitInstruction.o
DIST          = ../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/g++.conf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/unix.conf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/linux.conf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/qconfig.pri \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/modules/qt_webkit_version.pri \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt_functions.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt_config.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/exclusive_builds.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/default_pre.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/debug.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/default_post.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/unix/thread.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/moc.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/warn_on.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/resources.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/uic.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/yacc.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/lex.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/include_source_dir.prf \
		GameBoy.pro
QMAKE_TARGET  = GameBoy
DESTDIR       = 
TARGET        = GameBoy

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: GameBoy.pro  ../QtSDK/Desktop/Qt/474/gcc/mkspecs/linux-g++/qmake.conf ../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/g++.conf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/unix.conf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/linux.conf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/qconfig.pri \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/modules/qt_webkit_version.pri \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt_functions.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt_config.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/exclusive_builds.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/default_pre.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/debug.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/default_post.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/unix/thread.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/moc.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/warn_on.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/resources.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/uic.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/yacc.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/lex.prf \
		../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/include_source_dir.prf
	$(QMAKE) -spec ../QtSDK/Desktop/Qt/474/gcc/mkspecs/linux-g++ CONFIG+=debug -o Makefile GameBoy.pro
../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/g++.conf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/unix.conf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/linux.conf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/qconfig.pri:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/modules/qt_webkit_version.pri:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt_functions.prf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt_config.prf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/exclusive_builds.prf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/default_pre.prf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/debug.prf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/default_post.prf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt.prf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/unix/thread.prf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/moc.prf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/warn_on.prf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/resources.prf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/uic.prf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/yacc.prf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/lex.prf:
../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/include_source_dir.prf:
qmake:  FORCE
	@$(QMAKE) -spec ../QtSDK/Desktop/Qt/474/gcc/mkspecs/linux-g++ CONFIG+=debug -o Makefile GameBoy.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/GameBoy1.0.0 || $(MKDIR) .tmp/GameBoy1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/GameBoy1.0.0/ && $(COPY_FILE) --parents ROM/ROMLoader.h ROM/ROMHeader.h CPU/CPU.h CPU/ALU.h CPU/Register.h CPU/Loads.h CPU/Jumps.h Memory.h gameboy.h macro.h GPU/GPU.h CPU/Interruption.h GPU/Sprite.h GPU/Attribute.h CPU/BitInstruction.h .tmp/GameBoy1.0.0/ && $(COPY_FILE) --parents main.cpp ROM/ROMLoader.cpp CPU/CPU.cpp gameboy.cpp Memory.cpp GPU/GPU.cpp CPU/Interruption.cpp GPU/Sprite.cpp GPU/Attribute.cpp CPU/BitInstruction.cpp .tmp/GameBoy1.0.0/ && (cd `dirname .tmp/GameBoy1.0.0` && $(TAR) GameBoy1.0.0.tar GameBoy1.0.0 && $(COMPRESS) GameBoy1.0.0.tar) && $(MOVE) `dirname .tmp/GameBoy1.0.0`/GameBoy1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/GameBoy1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

main.o: main.cpp Buffer.h \
		gameboy.h \
		Memory.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

ROMLoader.o: ROM/ROMLoader.cpp ROM/ROMLoader.h \
		Buffer.h \
		ROM/ROMHeader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ROMLoader.o ROM/ROMLoader.cpp

CPU.o: CPU/CPU.cpp CPU/CPU.h \
		macro.h \
		Memory.h \
		Buffer.h \
		CPU/Interruption.h \
		CPU/Register.h \
		CPU/ALU.h \
		CPU/Loads.h \
		CPU/Jumps.h \
		CPU/BitInstruction.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CPU.o CPU/CPU.cpp

gameboy.o: gameboy.cpp gameboy.h \
		Memory.h \
		Buffer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gameboy.o gameboy.cpp

Memory.o: Memory.cpp Memory.h \
		Buffer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Memory.o Memory.cpp

GPU.o: GPU/GPU.cpp GPU/GPU.h \
		Memory.h \
		Buffer.h \
		GPU/Attribute.h \
		macro.h \
		GPU/Sprite.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GPU.o GPU/GPU.cpp

Interruption.o: CPU/Interruption.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Interruption.o CPU/Interruption.cpp

Sprite.o: GPU/Sprite.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Sprite.o GPU/Sprite.cpp

Attribute.o: GPU/Attribute.cpp GPU/Attribute.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Attribute.o GPU/Attribute.cpp

BitInstruction.o: CPU/BitInstruction.cpp CPU/BitInstruction.h \
		CPU/Register.h \
		macro.h \
		CPU/CPU.h \
		Memory.h \
		Buffer.h \
		CPU/Interruption.h \
		CPU/ALU.h \
		CPU/Loads.h \
		CPU/Jumps.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BitInstruction.o CPU/BitInstruction.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

