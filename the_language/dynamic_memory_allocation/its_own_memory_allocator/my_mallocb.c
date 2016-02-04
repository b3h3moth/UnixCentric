#include "my_mallocb.h"

// L'allocatore e' inizializzato
int init = 0;

// Puntatore all'inizio dell'area di memoria da gestire
void *beginning_memory;

// Individua l'ultimo indirizzo valido
void *last_address;
