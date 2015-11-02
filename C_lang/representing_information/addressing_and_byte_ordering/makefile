CC		= gcc
CFLAGS	= -std=c11 -Wall -pedantic

byte_representation: byte_representation.o show_bytes.o
	$(CC) $(CFLAGS) -o byte_representation byte_representation.o show_bytes.o

zero_extension: expanding_bit_1_zero_extension.o show_bytes.o
	$(CC) $(CFLAGS) -o zero_extension expanding_bit_1_zero_extension.o show_bytes.o

sign_extension: expanding_bit_2_sign_extension.o show_bytes.o
	$(CC) $(CFLAGS) -o sign_extension expanding_bit_2_sign_extension.o show_bytes.o

byte_representation.o: byte_representation.c show_bytes.h
	$(CC) $(CFLAGS) -c byte_representation.c

show_bytes.o: show_bytes.c show_bytes.h
	$(CC) $(CFLAGS) -c show_bytes.c

zero_extension.o: expanding_bit_1_zero_extension.c show_bytes.h
	$(CC) $(CFLAGS) -c expanding_bit_1_zero_extension.c


sign_extension.o: expanding_bit_2_sign_extension.c show_bytes.h
	$(CC) $(CFLAGS) -c expanding_bit_2_sign_extension.c

clean:
	rm -rf *.o
	rm -rf byte_representation 
	rm -rf sign_extension 
	rm -rf zero_extension
