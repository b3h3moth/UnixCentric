CC		= gcc
CFLAGS	= -std=c11 -Wall -pedantic
OBJS	= main.o hardware_components.o readline.o
TARGET  = hwcomponent.out
VAR		= $(wildcard *.c)

$(TARGET):	$(OBJS)
	$(CC) $(CFLAGS) $(VAR) -o $(TARGET)

clean:
	rm -rf $(OBJS) $(TARGET)
