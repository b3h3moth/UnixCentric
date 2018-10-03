CFLAGS=-Wall -pedantic
LD = gcc
CC = gcc
OBJS = main.o sorted_sequence.o
TARGET = sortedsequence.out

$(TARGET): $(OBJS)
	$(LD) -o $@ $(CFLAGS) $(OBJS)

main.o: main.c sorted_sequence.h
	$(CC) -c main.c

sorted_sequence: sorted_sequence.c sorted_sequence.h

clean:
	rm -rf *.o *.txt *.out *.core
