#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

/* Una fifo e' chiamata talvolta 'named pipe' ossia 'pipe con nome', questo
perche' a differenza di una pipe e' identificata mediante un nome, inoltre e'
vista come un file, per cui per utilizzarla possono essere adoperate le
comuni funzioni per l'I/O di basso livello non bufferizzato (open, read, write,
etc...).

Creare una fifo e' come creare un file, essa infatti e' vista proprio come un
file per cui puo' essere utilizzata da processi differenti.

HEADER    : <sys/stat.h>
PROTOTYPE : int mkfifo(const char *pathname, mode_t mode);
SEMANTICS : La funzione mkfifo() crea il file 'pathname' con modalita' di 
            accesso definite da 'mode'.
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    return(EXIT_SUCCESS);
}
