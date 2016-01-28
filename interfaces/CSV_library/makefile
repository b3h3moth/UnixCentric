CC      =  cc
CFLAGS  =  -pedantic -Wall -std=c11
TARGET  =  execsv

OBJS    =  main.o  csv.o

$(TARGET): $(OBJS)
	@echo "linking ..."
	@$(CC)  $^ -o $@

$(OBJS): csv.h
	$(CC)  $(CFLAGS) -c  $*.c

relink:
	@echo "relinking ..."
	@$(CC)  $(CFLAGS)  -o $(TARGET)  $(OBJS)  $(LIBS)

clean:
	rm -rf $(OBJS) $(TARGET)
