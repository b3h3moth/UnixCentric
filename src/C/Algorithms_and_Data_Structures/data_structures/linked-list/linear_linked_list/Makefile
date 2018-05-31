LD = gcc
CC = gcc
CL = clang
OBJS = main.o linklinstruct.o
TARGET = linkedlinstruct.out

$(TARGET): $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)

main.o: main.c linklinstruct.h
	$(CC) -c main.c

linklinstruct: linklinstruct.c linklinstruct.h
	$(CC) -c linklinstruct.c

clean:
	rm -rf *.o $(TARGET) *.txt *.out
