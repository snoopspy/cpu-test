all: cpu_test

cpu_test: main.o
	g++ -O2 -o cpu_test main.o -pthread

main.o:
	g++ -O2 -std=c++0x -c -o main.o main.cpp

clean:
	rm -f cpu_test
	rm -f *.o

