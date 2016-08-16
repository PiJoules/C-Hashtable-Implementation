.PHONY: all

EXE = test_hashtable

OBJECTS = hashtable.o

CC = gcc
CSTANDARD = c99
override CFLAGS += -std=$(CSTANDARD) -Wall

all: $(EXE)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(EXE): $(EXE).c $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXE) $(EXE).c $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(EXE)

test: $(EXE)
	valgrind --leak-check=yes ./$(EXE)


