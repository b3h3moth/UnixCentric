#include <stdio.h>
#include <stdlib.h>

/* Su diverse implementazioni UNIX l'ambiente di programmazione C fornisce
alcune variabili globali per ottenere l'indirizzo del successivo byte di
specifici segmenti del layout della memoria di un processo. Essi sono:
- etext, la fine del segmento 'text';
- edata, la fine del segmento 'data' (dati inizializzati);
-   end, la fine del segmento 'bss' (dati non inizializzati).
*/

extern char etext, edata, end;

int main(void) {

    puts("Print the next byte past of some Memory Layout segments:");

    printf("         \'program text\' (etest): %10p\n", (void*)&etext);
    printf("     \'initialized data\' (edata): %10p\n", (void*)&edata);
    printf("\'uninitialized data, bss\' (end): %10p\n", (void*)&end);

    return(EXIT_SUCCESS);
}
