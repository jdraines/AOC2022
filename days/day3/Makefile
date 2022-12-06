DAY = day3
all: $(DAY)

CC=g++
CFLAGS=-g
ODIR=obj
UTILS_DIR = ../../utils
DEPS = $(UTILS_DIR)/input.h ./$(DAY)lib.cpp
OBJ = $(ODIR)/input.o $(ODIR)/$(DAY).o $(ODIR)/$(DAY)lib.o

$(ODIR)/input.o: $(UTILS_DIR)/input.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/$(DAY)lib.o: ./$(DAY)lib.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/$(DAY).o: ./$(DAY).cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(DAY): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm ./$(DAY)