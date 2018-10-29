CC      =  cc
CFLAGS  =  -pedantic -Wall -std=c11
TARGET  =  stack

OBJS    =  main.o  stack.o

$(TARGET): $(OBJS)
	@echo "linking ..."
	@$(CC)  $^ -o $@

$(OBJS): stack.h
	$(CC)  $(CFLAGS)  $(INCLS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(TARGET)  $(OBJS)  $(LIBS)

clean:
	rm -rf $(OBJS) $(TARGET)
