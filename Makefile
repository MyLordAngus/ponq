# Compiler
CXX := g++
CXXFLAGS := -g -Wall -pedantic

# Include path
INCPATHS = -I/usr/include/QtCore -I/usr/include/QtGui

LIBS = -lQtCore -lQtGui

LINKER := ld

all: main.cpp
	${CXX} ${CXXFLAGS} ${INCPATHS} ${LIBS} main.cpp -o ponq
