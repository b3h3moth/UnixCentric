#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*
La pipe crea un flusso di comunicazione unidirezionale half-duplex, per cui un
processo scrive - mediante write() -  e un altro processo legge - mediante 
read().

Nota: POSIX.1 consente anche la creazione di pipe bidirezionali, full duplex, 
      il canale di comunicazione aperto sara' in lettura e scrittura su 
      entrambi i file descriptor. Questa soluzione tuttavia risulta essere non
      portabile quanto la pipe unidirezionale half-duplex.

Le pipe possono essere utilizzate solo da processi che hanno antenati in comune,
generalmente viene creata da un processo che successivamente eseguira' una 
chiamata a fork(), per cui la pipe sara' utlizzata per la comunicazione tra il 
processo padre e il processo figlio.

Per creare una pipe si utilizza la sistem call pipe().

HEADER    : <unistd.h>
PROTOTYPE : int pipe(int fd[2]);
SEMANTICS : Il parametro della funzione pipe() e' il file descriptor 'fd', un 
            array con due interi: 
            - fd[0] e' il file descriptor da usare per la lettura della pipe;
            - fd[1] e' il file descriptor da usare per la scrittura nella pipe. 
            L'output di fd[0] e' l'input di fd[1].
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
In sostanza la funzione pipe() non fa altro che chiedere al kernel la creazione
di un canale o buffer di comunicazione, per cui puo' essere considerata come un
file a cui si accede in lettura e scrittura.

La write() aggiunge dati sulla pipe
La read() legge i dati dalla pipe, togliendoli da essa
*/


/* Si utilizza una pipe per l'invio di informazioni dal processo figlio al 
processo padre. */

int main(int argc, char *argv[]) {

    
    return(EXIT_SUCCESS);
}
