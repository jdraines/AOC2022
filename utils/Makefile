CFLAGS = -std=c++11

main: input test
	g++ -o main input.o test.o $(CFLAGS)

intput: input.cpp
	g++ -c input.cpp $(CFLAGS)

test: test.cpp
	g++ -c test.cpp $(CFLAGS)

