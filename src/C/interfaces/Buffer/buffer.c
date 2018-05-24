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
void dealloca(Buffer *buf) {
    free(buf->data);
    free(buf);
}

/* Move the index at the initial position within the Buffer */
void reset(Buffer *buf) {
    buf->pos = 0;
}

/* Setup the Buffer name */
void set_name(Buffer *buf, const char *name) {
    strncpy(buf->name, name, strlen(MAX_NAME_DIM));
}

/* Returns a random character 
   A + [0,25] = random character with a range from 0 to 25 */
static char random_ch() {
    return rand()%26 + 'A';
}

/* Buffer initialization through random characters.
   It writes random characters within the Buffer. */
void init_random(Buffer *buf) {
    char ch = buf_putc(buf, random_ch());

    if (ch != EOB) /* If the Buffer is not full, we can fill it */
        init_random(buf);
}


/* Buffer initialization through a string */
void init(Buffer *buf, const char *str) {
    if (str[0] == '\0')
        reset(buf);
    else {
        char ch = buf_putc(buf, str[0]);

        if (ch != EOB) /* If the Buffer is not full, we can fill it */
            init(buf, str + 1);
    }
}


/* Read next character within the Buffer, increment by one the index,
   It Returns EOB if the End Of Buffer has been reached. */
char buf_getc(Buffer *buf) {
    char cr = EOB;
    
    if (buf->pos < buf->size) {
        cr = buf->data[buf->pos];
        buf->pos++;
    } else if (buf->pos == buf->size) { /* End of the Buffer */
        reset(buf);
        cr = EOB;
    }
    return cr;
}

/* Write next character within the Buffer, increment by one the index,
   It Returns EOB if the End Of Buffer has been reached. */
char buf_putc(Buffer *buf, char *c) {
    char cr = EOB;

    if (buf->pos < buf->size) {
        buf->data[buf->pos] = c;
        cr = c;
        buf->pos++;
    } else if (buf->pos == buf->size) { /* End of the Buffer */
        reset(buf);
        cr = EOB;
    }
    return cr;
}

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
