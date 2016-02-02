#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct mem_block *t_mem_block;

struct mem_block {
    size_t      size;
    int         free;
    t_mem_block next;
};
