LD = gcc
CC = gcc
CL = clang
OBJS = main.o linlinklst.o
TARGET = linear_linked_list

$(TARGET): $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)

main.o: main.c linlinklst.h
	$(CC) -c main.c

linlinklst: linlinklst.c linlinklst.h
	$(CC) -c linlinklst.c

clean:
	rm -rf *.o $(TARGET) *.txt
