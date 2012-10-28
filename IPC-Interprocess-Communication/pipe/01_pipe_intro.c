#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*
La pipe crea un flusso di comunicazione unidirezionale half-duplex, per cui un
processo scrive - mediante write() -  e un altro processo legge - mediante 
read().

Le pipe possono essere utilizzate solo da processi che hanno antenati in comune,
generalmente viene creata da un processo che successivamente eseguira' una 
chiamata a fork(), per cui la pipe sara' utlizzata per la comunicazione tra il 
processo padre e il processo figlio.


HEADER    : 
PROTOTYPE : 
SEMANTICS : 
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    return(EXIT_SUCCESS);
}
