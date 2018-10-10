#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE    3

/* Le 'union' seguono la sintassi delle 'struct', la differenza sostanziale
risiede nel fatto che, a differenza delle 'struct', i membri delle 'union' 
condividono la memoria, il compilatore infatti alloca memoria sufficiente per 
contenere il membro col maggior peso.

Nel caso specifico vi e' uno 'short' da 2 byte, un 'int' da 4 byte e un 'long'
da 4 byte, sara' pertanto allocata una porzione di memoria di 4 byte.
*/

typedef union {
    short srt_type;
    int int_type;
    long l_type;
} IntegerFamily;

/* Il tipo di dato union e' perfetto per la creazione di strutture dati
composite. Lo scopo del programma infatti e' di realizzare un vettore i cui
membri saranno interi di diverso tipo. */

int main(void) {
    /* Dichiarazione del vettore di tipo 'IntegerFamily', i cui membri possono
    essere di tipo 'short', 'int' e 'long'. */
    IntegerFamily vec[MAX_SIZE];

    vec[0].srt_type = 30000;
    vec[1].int_type = 2000000;
    vec[2].l_type = 2000000000l;
    
    printf("%d\n%d\n%li\n", vec[0].srt_type, vec[1].int_type, vec[2].l_type);

    printf("%d byte\n", sizeof(IntegerFamily));

    return(EXIT_SUCCESS);
}
