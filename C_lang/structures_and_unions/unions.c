#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE    3

/* Il tipo di dato union e' perfetto per la creazione di strutture dati
composite. Lo scopo del programma infatti e' di realizzare un vettore i cui
membri saranno interi di diverso peso. */

typedef union {
    short srt_type;
    int int_type;
    long l_type;
} IntegerFamily;

int main(void) {
    // Un vettore conterra' di diversi tipi di dato
    IntegerFamily vec[MAX_SIZE];

    vec[0].srt_type = 30000;
    vec[1].int_type = 2000000;
    vec[2].l_type = 2000000000l;
    
    printf("%d\n%d\n%li\n", vec[0].srt_type, vec[1].int_type, vec[2].l_type);

    return(EXIT_SUCCESS);
}
