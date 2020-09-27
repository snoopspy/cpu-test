all: cpu-test

cpu-test: main.o
	g++ -O2 -o cpu-test main.o -pthread

main.o:
	g++ -O2 -std=c++0x -c -o main.o main.cpp

clean:
	rm -f cpu-test
	rm -f *.o

