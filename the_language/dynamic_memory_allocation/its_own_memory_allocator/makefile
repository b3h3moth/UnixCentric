CC      =  cc
CFLAGS  =  -pedantic -Wall -std=c11 -D_BSD_SOURCE
TARGET  =  mallocs.out

OBJS    =  main.o xmalloc.o basic_malloc.o zmalloc.o

$(TARGET): $(OBJS)
	@echo "linking ... $(TARGET)"
	@$(CC)  $^ -o $@

relink:
	@echo "relinking ... $(TARGET)"
	@$(CC)  $(CFLAGS)  -o $(TARGET)  $(OBJS)  $(LIBS)

clean:
	rm -rf $(OBJS) $(TARGET)
