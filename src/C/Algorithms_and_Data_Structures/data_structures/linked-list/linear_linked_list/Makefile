

linear_linked_list: main.o linlinklst.o
	gcc -o linear_linked_list main.o linlinklst.o

main.o: main.c linlinklst.h
	gcc -c main.c

linlinklst: linlinklst.c linlinklst.h
	gcc -c linlinklst.c

clean:
	rm -rf *.o linear_linked_list
