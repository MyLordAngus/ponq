# Compiler
CXX := g++
CXXFLAGS := -g -Wall -pedantic -std=c++0x

# Include path
INCPATHS = `pkg-config --cflags QtCore QtGui`
LIBS = `pkg-config --libs QtCore QtGui`

all: main.o Ball.o
	${CXX} ${CXXFLAGS} ${LIBS} main.o Ball.o -o ponq

main.o: main.cpp
	${CXX} ${CXXFLAGS} ${INCPATHS} -o main.o main.cpp -c

Ball.o: Ball.cpp
	${CXX} ${CXXFLAGS} ${INCPATHS} -o Ball.o Ball.cpp -c

clean:
	rm *.o ponq
