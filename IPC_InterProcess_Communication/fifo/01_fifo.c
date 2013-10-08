#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/* Una fifo o altrimenti detta 'named pipe' - pipe con nome - a differenza di 
una pipe e' identificata mediante un nome, gode di permessi specifici ed e' 
vista a tutti gli effetti come fosse un file, per cui le  comuni funzioni per 
l'I/O di basso livello non bufferizzato come open o read  possono essere 
utilizzate.

Creare una fifo e' come creare un file - in realta' la definizione corretta e'
file speciale - e puo' essere utilizzata da processi differenti.

HEADER    : <sys/stat.h>
PROTOTYPE : int mkfifo(const char *pathname, mode_t mode);
SEMANTICS : La funzione mkfifo() crea la FIFO, corrispondente al file speciale
            indicato da 'pathname' con modalita' di accesso definite da 'mode'.
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    pid_t pid;

    /* Si verifica che vi sia un argomento fornito al programma */
    if (argc != 2) {
        fprintf(stderr, "Uso: %s fifoname\n", argv[0]);
        exit(EXIT_FAILURE);
    }


    return(EXIT_SUCCESS);
}
