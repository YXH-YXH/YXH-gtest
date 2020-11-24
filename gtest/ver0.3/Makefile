.PHONY: clean
all:main.o test.o
	g++ main.o test.o
main.o: main.cpp
	g++ -c main.cpp
test.o:test.h test.cc
	g++ -c test.cc
clean:
	rm -rf a.out *.o main
