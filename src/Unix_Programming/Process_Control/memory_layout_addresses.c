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
    printf("next byte past of \'program text\' (etest): %10p\n", (void*)&etext);
    return(EXIT_SUCCESS);
}
