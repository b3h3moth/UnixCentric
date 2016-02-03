#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define META_BLOCK    sizeof(struct mem_block)

typedef struct mem_block *t_mem_block;

struct mem_block {
    size_t      size;
    t_mem_block next;
    int         free;
};

/* L'allocazione della memoria sara' effettuata mediante una linked-list,
base punta alla testa della lista */
void *base = NULL;
