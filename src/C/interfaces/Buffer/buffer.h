#ifndef BUFFER_H
#define BUFFER_H

const int MAX_NAME_DIM = 20;

/* The Buffer of characters */
typedef struct {
    int size;                   /* The Buffer size */
    char *data; 
    char name[MAX_NAME_DIM];    /* The Buffer */
    int pos;                    /* The index of the buffer */
} Buffer;

#endif
