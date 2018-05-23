#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"

/* Dynamic memory allocation of the Buffer */
Buffer alloca(int size const char *name) {
    Buffer *buf = (Buffer*)malloc(sizeof(Buffer));

    buf->data = (char*)malloc(size * sizeof(char));
    buf->size = size;
    buf->pos = 0;
    set_name(buf, name);
    
    return buf;
}

/* Releases the Buffer memory */
void dealloca(Buffer *buf);

/* Move the index at the initial position within the Buffer */
void reset(Buffer *buf);

/* Setup the Buffer name */
void set_name(Buffer *buf, const char *name);

/* Buffer initialization through random characters */
void init_random(Buffer *buf);

/* Buffer initialization through a string */
void init(Buffer *buf, const char *str);

/* Read next character within the Buffer, increment by one the index,
   It Returns EOB if the End Of Buffer has been reached. */
char buf_getc(Buffer *buf);

/* Write next character within the Buffer, increment by one the index,
   It Returns EOB if the End Of Buffer has been reached. */
char buf_putc(Buffer *buf, char *c);

/* Print the contents of the Buffer */
void buf_print(Buffer *buf);

/* Copy the contents of the Buffer from source to the destination */
void buf_copy(Buffer *bsrc, Buffer *bdst);

/* Copy the contents of the Buffer from source to the destination
   inverse order. */
void buf_inverse_copy(Buffer *bsrc, Buffer *bdst);

/* Count how many occurence of the ASCII character there are within the 
   Buffer */
int count(Buffer *buf, char c);

/* Concatenate two Buffer into new one with its own name */
Buffer *buf_concatenate(Buffer *bufa, Buffer *bufb, const char *name);

/* Check if the Buffer is palindrome */
int palindrome(Buffer *buf);
