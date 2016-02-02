#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct mem_block *t_mem_block;

struct mem_block {
    size_t      size;
    int         free;
    t_mem_block next;
};

int main(void) {
    t_mem_block block;

    // old break
    block = sbrk(0);
    sbrk(sizeof(struct mem_block) + 4);
    block->size = 4;

    return(EXIT_SUCCESS);
}
