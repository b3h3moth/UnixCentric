#include <unistd.h>
#include "my_mallocb.h"

// L'allocatore e' inizializzato
int init_allocator = 0;

// Puntatore all'inizio dell'area di memoria da gestire
void *beginning_memory;

// Individua l'ultimo indirizzo valido, riconducibile a 'break'
void *last_address;

// Inizializza l'allocatore di memoria
void init_alloc(void) {
    // Salva l'ultimo indirizzo valido puntato da 'break'
    last_address = sbrk(0);

    beginning_memory = last_address;

    init_allocator = 1;
}
