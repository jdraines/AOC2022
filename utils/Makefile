CC = g++
CFLAGS = -g
ODIR=obj

DEPS = input.h
OBJ = $(ODIR)/input.o $(ODIR)/test.o

all: test

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(ODIR)/input.o: ./input.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(ODIR)/test.o: ./test.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

