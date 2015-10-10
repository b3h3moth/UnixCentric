#ifndef SHOW_BYTES_H
#define SHOW_BYTES_H

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len);
void show_int(int data);
void show_float(float data);
void show_pointer(void *data);
void show_short(short data);
void show_double(double data);
void show_long(long data);

#endif
