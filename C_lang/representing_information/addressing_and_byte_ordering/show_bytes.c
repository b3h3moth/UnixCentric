#include <stdio.h>
#include "show_bytes.h"

// Returns each byte in hexadecimal format
void show_bytes(byte_pointer start, int len) {
    for (int i=0; i<len; i++)
        printf("%.2x ", start[i]);

    printf("\n");
}

// Show 'int' data type
void show_int(int data) {
    // printf("[%d:    int] - ", data);
    show_bytes((byte_pointer) &data, sizeof(int));
}

// Show 'float' data type
void show_float(float data) {
    // printf("[%.f:  float] - ", data);
    show_bytes((byte_pointer) &data, sizeof(float));
}

// Show 'void' data type
void show_pointer(void *data) {
    // printf("[%d: void *] - ", (int)data);
    show_bytes((byte_pointer) &data, sizeof(void *));
}

// Show 'short' data type
void show_short(short data) {
    // printf("[%d:  short] - ", data);
    show_bytes((byte_pointer) &data, sizeof(short));
}

// Show 'double' data type
void show_double(double data) {
    // printf("[%g: double] - ", data);
    show_bytes((byte_pointer) &data, sizeof(double));
}

// Show 'long' data type
void show_long(long data) {
    // printf("[%ld:   long] - ", data);
    show_bytes((byte_pointer) &data, sizeof(long));
}
