# Compiler
CXX := g++
CXXFLAGS := -g -Wall -pedantic

# Include path
INCPATHS = -I/usr/include/QtCore -I/usr/include/QtGui

LIBS = -lQtCore -lQtGui

all: main.cpp Ball.o
	${CXX} ${CXXFLAGS} ${INCPATHS} ${LIBS} main.cpp Ball.o -o ponq

Ball.o: Ball.cpp
	${CXX} ${CXXFLAGS} ${INCPATHS} ${LIBS} Ball.cpp -o Ball.o -c

clean:
	rm *.o ponq
