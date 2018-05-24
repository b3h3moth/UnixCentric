#ifndef BUFFER_H
#define BUFFER_H

#define MAX_NAME_DIM 20
#define EOB ' '

/* The Buffer of characters */
typedef struct {
    int size;                   /* The Buffer size */
    char *data; 
    char name[MAX_NAME_DIM];    /* The Buffer */
    int pos;                    /* The index of the buffer */
} Buffer;

/* Dynamic memory allocation of the Buffer */
Buffer *buf_alloc(int size, const char *name);

/* Releases the Buffer memory */
void buf_dealloc(Buffer *buf);

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
char buf_putc(Buffer *buf, char c);

/* Print the contents of the Buffer */
void buf_print(Buffer *buf);
void print(Buffer *buf);

/* Copy the contents of the Buffer from source to the destination */
void buf_copy(Buffer *bdst, Buffer *bsrc);

/* Copy the contents of the Buffer from source to the destination
   inverse order. */
void buf_inverse_copy(Buffer *bdst, Buffer *bsrc);

/* Count how many occurence of the ASCII character there are within the 
   Buffer */
int count(Buffer *buf, char c);

/* Concatenate two Buffer into new one with its own name */
Buffer *buf_concatenate(Buffer *bufa, Buffer *bufb, const char *name);
void concatenate(Buffer *bnew, Buffer *bufa, Buffer *bufb);

/* Check if the Buffer is palindrome */
int palindrome(Buffer *buf);

#endif
