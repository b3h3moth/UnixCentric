#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

/* L'allocazione della memoria puo' essere gestita anche mediante una mappatura
della memoria stessa utilizzando le syscall mmap() e munmap(). 

HEADER   : <sys/mman.h>
PROTOTYPE: void *mmap(void *addr, size_t length, int prot, int flags, 
                      int fd, off_t offset);

mmap() crea una nuova mappa di memoria nello spazio virtuale degli indirizzi
del processo chiamante. L'indirizzo di partenza e' indicato da 'addr', mentre
la lunghezza della mappa e' indicata da 'length'.

Se 'addr' vale NULL sara' il kernel a scegliere l'indirizzo dal quale creare la
mappa, che corrisponde peraltro alla modalita' piu' portabile per la creazione
di una nuova mapppa; se invece 'addr' non e' impostato a NULL allora il 
kernel prendera' in considerazione tale indirizzo per posizionare la mappa; il
kernel linux iniziera' la mappatura dalla pagina "confinante" immediatamente
successiva - da ricordare che una pagina e' di 4096 Kb.

'prot' indica la protezione di memoria della mappa; 'flags' determina il tipo
di mappa, ovvero se e' visibile agli altri processi mappati nella stessa 
regione e se realizzata mediante file; 'fd' e' il file descriptor di una
porzione di un eventuale file da mappare; 'offset' infine riguarda per 
l'appunto l'offset del file 'fd' a partire dal quale inizia la mappatura.

Nota: 'fd' e 'offset' sono generalmente ignorati.

In caso di successo, ritorna un puntatore all'area mappata; in caso di errore
restituisce MAP_FAILED, ovvero (void *)-1.
*/

int main(void) {
    int *addr;

    return(EXIT_SUCCESS);
}
