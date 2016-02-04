CC      =  cc
CFLAGS  =  -pedantic -Wall -std=c11
OBJS    =  main.o  stack.o
TARGET  =  stack

$(TARGET): $(OBJS)
	@echo "linking ..."
	@$(CC)  $^ -o $@

$(OBJS): stack.h
	$(CC)  $(CFLAGS)  -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(TARGET)  $(OBJS)  $(LIBS)

clean:
	rm -rf $(OBJS) $(TARGET)
