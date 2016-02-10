#ifndef YMALLOC
#define YMALLOC

#include <stdio.h>

struct memory_block {
    int free;
    size_t size;
};

// Prototipi
void init_alloc(void);
void free_mem(void *first_byte);
void my_mallocb(size_t size);

#endif
