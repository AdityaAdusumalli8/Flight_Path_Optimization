CC=g++
FLAGS=-std=c++1y -stdlib=libc++ -c -g -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function
LDFLAGS=-std=c++1y -stdlib=libc++ -lc++abi

all: main.o graph.o airport.o routes.o filereader.o graphNode.o
	$(CC) $(LDFLAGS) main.o graph.o airport.o routes.o filereader.o graphNode.o -o main

test: tests.o main.o graph.o airport.o routes.o filereader.o graphNode.o
	$(CC) $(LDFLAGS) test.o main.o graph.o airport.o routes.o filereader.o graphNode.o -o test

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

tests.o: tests.cpp
	$(CC) $(FLAGS) tests.cpp

graph.o: graph.cpp
	$(CC) $(FLAGS) graph.cpp

graphNode.o: graphNode.cpp
	$(CC) $(FLAGS) graphNode.cpp

airport.o: airport.cpp
	$(CC) $(FLAGS) airport.cpp

routes.o: routes.cpp
	$(CC) $(FLAGS) routes.cpp

filereader.o: filereader.cpp
	$(CC) $(FLAGS) filereader.cpp

clean:
	rm -f *.o
	rm main
	rm test
