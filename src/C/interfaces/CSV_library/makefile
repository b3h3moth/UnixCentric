CC      =  cc
CFLAGS  =  -pedantic -Wall -std=c99
TARGET  =  csv.out

OBJS    =  main.o  csv.o

$(TARGET): $(OBJS)
	@echo "linking ... $(TARGET)"
	@$(CC)  $^ -o $@

$(OBJS): csv.h
	$(CC)  $(CFLAGS) -c  $*.c

relink:
	@echo "relinking ... $(TARGET)"
	@$(CC)  $(CFLAGS)  -o $(TARGET)  $(OBJS)  $(LIBS)

clean:
	rm -rf $(OBJS) $(TARGET)
