#include <stdio.h>
#include <stdlib.h>

/* Lo scopo del  programma e' la realizzazione di un file 'write lock'
utilizzando la funzione fcntl().

Tra le operazioni piu' comuni della funzione fcntl() vi e' la possibilita' di 
mettere un blocco in lettura o in scrittura su un file. Il blocco in lettura e'
posto su un file descriptor leggibile, anche in contemporanea tra piu' 
processi; il blocco in scrittura invece va posto su un file descriptor 
scrivibile, ma solo un processo puo' beneficiarne. Il medesimo file non puo' 
essere bloccato sia in lettura sia in scrittura. */

int main(void) {

    return(EXIT_SUCCESS);
}
