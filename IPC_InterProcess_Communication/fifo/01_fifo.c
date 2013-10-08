#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

/* Una fifo o altrimenti detta 'named pipe' - pipe con nome - a differenza di 
una pipe e' identificata mediante un nome, gode di permessi specifici ed e' 
vista a tutti gli effetti come fosse un file, per cui le  comuni funzioni per 
l'I/O di basso livello non bufferizzato come open o read  possono essere 
utilizzate.

Creare una fifo e' come creare un file e puo' essere utilizzata da processi 
differenti.

HEADER    : <sys/stat.h>
PROTOTYPE : int mkfifo(const char *pathname, mode_t mode);
SEMANTICS : La funzione mkfifo() crea il file 'pathname' con modalita' di 
            accesso definite da 'mode'.
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
*/

int main(void) {
    return(EXIT_SUCCESS);
}
