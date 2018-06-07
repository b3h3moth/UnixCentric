LD = gcc
CC = gcc
OBJS = main.o sorted_sequence.o
TARGET = sortedsequence.out

$(TARGET): $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)

main.o: main.c sorted_sequence.h
	$(CC) -c main.c

sorted_sequence: sorted_sequence.c sorted_sequence.h
	$(CC) -c sorted_sequence.c

clean:
	rm -rf *.o $(TARGET) *.txt *.out *.core
