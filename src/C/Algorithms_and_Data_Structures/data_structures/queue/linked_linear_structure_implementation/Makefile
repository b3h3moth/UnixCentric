LD = gcc
CC = gcc
OBJS = main.o type_queue.o
TARGET = queue.out

$(TARGET): $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)

main.o: main.c type_queue.h
	$(CC) -c main.c

type_queue: type_queue.c type_queue.h
	$(CC) -c type_queue.c

clean:
	rm -rf *.o $(TARGET) *.txt *.out *.core
