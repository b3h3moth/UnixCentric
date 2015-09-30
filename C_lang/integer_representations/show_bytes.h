#ifndef SHOW_BYTES_H
#define SHOW_BYTES_H

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len);
void show_int(int x);
void show_float(float x);
void show_pointer(void *x);

#endif
