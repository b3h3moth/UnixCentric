#include <stdio.h>
#include <stdlib.h>

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

'prot' indica la protezione di memoria della mappa; 'flags' determina se la
mappa dev'essere condivisa o privata; 'fd' riguarda la porzione di un eventuale
file da mappare; 'offset' riguarda l'eventuale settaggio dell'offset nel file
riferito da 'fd'- 'fd' e 'offset' sono generalmente ignorati.
*/

int main(void) {
    return(EXIT_SUCCESS);
}
