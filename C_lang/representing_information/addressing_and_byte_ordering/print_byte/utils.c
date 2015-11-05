#include <stdio.h>
#include <limits.h>

/* Per stampare correttamente i dati binari ed esadecimali e' necessario
verificare il byte-ordering, ovvero se l'architettura e' di tipo little-endian,
big-endian oppure ne' l'una ne' l'altra */
#if BYTE_ORDER == LITTLE_ENDIAN

#define FIRST_CHAR(ptr, size)   (ptr + size - 1)
#define NEXT_CHAR(ptr)        --(ptr)

#elif BYTE_ORDER == BIG_ENDIAN

#define FIRST_CHAR(ptr, size)   (ptr)
#define NEXT_CHAR(ptr)        ++(ptr)

#endif

int main(void) {
    return(EXIT_SUCCESS);
}
