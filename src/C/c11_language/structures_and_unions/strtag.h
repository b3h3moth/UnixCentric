#ifndef STRTAG_H
#define STRTAG_H

/* When a struct use a struct-tag, it doesn't allocate memory */
struct strtag {
    unsigned int year;
    unsigned int month;
    unsigned int dat;
};

#endif

/*
Within a .c file we can include this file and then working with the header:
#include "strtag.h"
*/

/* A good way to create a new type is:
typedef struct strtag NewType;

Then:

NewType data;

Now the memory will be allocated.
*/
