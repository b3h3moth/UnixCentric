CC = gcc
CFLAGS = -std=c11 -Wall -pedantic -D_BSD_SOURCE
OBJS= main.o my_malloc.o my_malloca.o my_mallocb.o
TARGET= mallocators

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c

my_malloc.o: my_malloc.c my_malloc.h
	$(CC) $(CFLAGS) -c my_malloc.h

my_malloca.o: my_malloca.c my_malloca.h
	$(CC) $(CFLAGS) -c my_malloca.h

my_mallocb.o: my_mallocb.c my_mallocb.h
	$(CC) $(CFLAGS) -c my_mallocb.h

clean:
	rm -rf $(OBJS) $(TARGET)
