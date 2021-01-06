CXX = g++
CXXFLAGS = -fopenmp
MKDIR = mkdir -p

LIBS = -fopenmp

directorios:
	$(MKDIR) build dist

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean main.o
	$(CXX) main.cpp -o dist/programa $(LIBS)
	rm -fr build

clean:
	rm -fr *.o *.png a.out core programa dist build

.DEFAULT_GOAL := all