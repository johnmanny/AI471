all: prob1

prob1.o: prob1.cpp
	g++ -g -Wall -std=c++11 -c prob1.cpp -o prob1.o

prob1: prob1.o
	g++ -g -Wall -std=c++11 prob1.o -o prob1

clean:
	rm prob1.o prob1
