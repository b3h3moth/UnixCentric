CC      =  cc
CFLAGS  =  -pedantic -Wall -std=c11
TARGET  =  conversions
SOURCE	= *.c
OBJS    =  main.o user_group_conversions.o

$(TARGET): $(OBJS)
	@$(CC)  $^ -o $@
	@echo Executable: $(TARGET)

$(OBJS): user_group_conversions.h
	$(CC)  $(CFLAGS)  $(INCLS) -c $(SOURCE)

clean:
	rm -rf $(OBJS) $(TARGET)
