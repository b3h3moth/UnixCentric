#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_malloc.h"

/* L'allocazione della memoria sara' effettuata mediante una linked-list,
base punta alla testa della lista */
void *base = NULL;

// Prototipi
t_mem_block find_block(t_mem_block *last, size_t size) {
    ;
}
