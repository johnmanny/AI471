all: nndemo

nndemo.o: nndemo.cpp
	g++ -g -Wall -std=c++11 -c nndemo.cpp -o nndemo.o

nndemo: nndemo.o
	g++ -g -Wall -std=c++11 nndemo.o -o nndemo

clean:
	rm nndemo.o nndemo
