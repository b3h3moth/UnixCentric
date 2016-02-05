CC      =  cc
CFLAGS  =  -pedantic -Wall -std=c11 -D_BSD_SOURCE
TARGET  =  my_malloc.out

OBJS    =  main.o my_malloc.o my_malloca.o my_mallocb.o

$(TARGET): $(OBJS)
	@echo "linking ... $(TARGET)"
	@$(CC)  $^ -o $@

$(OBJS): my_malloc.c my_malloca.c my_mallocb.c
	$(CC)  $(CFLAGS) -c  $*.c

relink:
	@echo "relinking ... $(TARGET)"
	@$(CC)  $(CFLAGS)  -o $(TARGET)  $(OBJS)  $(LIBS)

clean:
	rm -rf $(OBJS) $(TARGET)
