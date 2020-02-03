CC=gcc
CFLAGS=-I.
LIBS = -lncurses
all: flappy

%.o: %.c backend.h frontend.h
	$(CC) -c -o $@ $< $(CFLAGS)

flappy: main.o backend.o frontend.o
	$(CC) -o flappy main.o backend.o frontend.o $(LIBS)

clean:
	rm -rf *.o *~ flappy