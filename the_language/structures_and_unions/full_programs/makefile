CC		= gcc
CFLAGS	= -std=c11 -Wall -pedantic
OBJS	= main.o hardware_components.o readline.o
TARGET  = hwcomponent.out

$(TARGET):	$(OBJS)
	$(CC) $^ -o $@

clean:
	rm -rf $(OBJS) $(TARGET)
