CC      =  cc
CFLAGS  =  -pedantic -Wall -std=c11
TARGET  =  blackboxes
SOURCE	= *.c
OBJS    =  main.o  addresslist.o

$(TARGET): $(OBJS)
	@$(CC)  $^ -o $@
	@echo Executable: $(TARGET)

$(OBJS): addresslist.h
	$(CC)  $(CFLAGS)  $(INCLS) -c $(SOURCE)

clean:
	rm -rf $(OBJS) $(TARGET)
