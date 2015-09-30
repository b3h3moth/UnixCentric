#include "show_bytes.h"

// Returns each byte in hexadecimal format
void show_bytes(byte_pointer start, int len) {
    int i;

    for (i=0; i<len; i++) {
        printf("%.2x ", start[i]);
    }

    printf("(%d byte)\n", len);
}

// Show 'int' data type
void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

// Show 'float' data type
void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

// Show 'void' data type
void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}
