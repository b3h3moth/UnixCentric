#include <stdio.h>
#include <stdlib.h>

/* Il tipo di dato union e' perfetto per la creazione di strutture dati
composite. Lo scopo del programma infatti e' di realizzare un vettore i cui
membri saranno interi di diverso peso. */

typedef union {
    short srt_type;
    int int_type;
    long l_type;
} IntegerFamily;

int main(void) {
    return(EXIT_SUCCESS);
}
