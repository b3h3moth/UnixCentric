#include <stdio.h>
#include "show_bytes.h"

// Returns each byte in hexadecimal format
void show_bytes(byte_pointer start, int len) {

    for (int i=0; i<len; i++) {
        printf("%.2x ", start[i]);
    }

    printf("(%d byte)\n", len);
}

// Show 'int' data type
void show_int(int data) {
    show_bytes((byte_pointer) &data, sizeof(int));
}

// Show 'float' data type
void show_float(float data) {
    show_bytes((byte_pointer) &data, sizeof(float));
}

// Show 'void' data type
void show_pointer(void *data) {
    show_bytes((byte_pointer) &data, sizeof(void *));
}

// Show 'short' data type
void show_short(short data) {
    show_bytes((byte_pointer) &data, sizeof(short));
}

// Show 'double' data type
void show_double(double data) {
    show_bytes((byte_pointer) &data, sizeof(double));
}

// Show 'long' data type
void show_long(long data) {
    show_bytes((byte_pointer) &data, sizeof(long));
}
