#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>

/* L'allocazione della memoria puo' essere gestita anche mediante una mappatura
della memoria stessa utilizzando le syscall mmap() e munmap(). 

Una mappa o mappatura puo' essere sostanzialmente di due tipi: 
1) File mapping.
2) Anonymous mapping.

HEADER   : <sys/mman.h>
PROTOTYPE: void *mmap(void *addr, size_t length, int prot, int flags, 
                      int fd, off_t offset);

mmap() crea una nuova mappa di memoria nello spazio virtuale degli indirizzi
del processo chiamante. L'indirizzo di partenza e' indicato da 'addr', mentre
'length' e' il numero di byte da mappare.

Se 'addr' vale NULL sara' il kernel a scegliere l'indirizzo dal quale creare la
mappa, che corrisponde peraltro alla modalita' piu' portabile per la creazione
di una nuova mapppa; se invece 'addr' non e' impostato a NULL allora il 
kernel prendera' in considerazione tale indirizzo per posizionare la mappa; il
kernel linux iniziera' la mappatura dalla pagina "confinante"  - da ricordare 
che una pagina e' di 4096 Kb.

'prot' indica la protezione della mappa, ovvero se i dati mappati possono
essere letti (PROT_READ), scritti (PROT_WRITE), eseguiti (PROT_EXEC) oppure se
non e' possibile addervi (PROT_NONE); 'flags' determina se i cambiamenti ai
dati mappati siano visibili agli altri processi e le eventuali modifiche
scritte su disco (MAP_SHARED) oppure no (MAP_PRIVATE); 'fd' e' il 
file-descriptor del file da mappare; 'offset' infine riguarda il punto a 
partire dal quale inizia la mappatura.

Nota: 'fd' e 'offset' sono generalmente ignorati.

In caso di successo, ritorna un puntatore all'area mappata; in caso di errore
restituisce MAP_FAILED, ovvero (void *)-1.
*/

int main(void) {
    void *addr;
    size_t len = 1;

    /*
    - addr impostato a NULL, per cui sara' il kernel a determinare l'indirizzo;
    - PROT_READ, PROT_WRITE, protezione impostata in lettura e scrittura;
    - MAP_PRIVATE,           la mappa sara' privata rispetto al processo e non
                             associata ad alcun file;
    - file descriptor settato a -1, quindi mappatura anonima;
    - l'offset del file impostato a 0.
    */
    addr = (char *)mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE , -1, 0);
    
    if (addr == MAP_FAILED) {
        fprintf(stderr, "Err.(%d) mmap(): %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    *((char *)addr) = 'a';
    printf("%c\n", *((char *)addr) );

    return(EXIT_SUCCESS);
}
