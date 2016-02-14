#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>

/* L'allocazione della memoria puo' essere gestita anche mediante una mappatura
della memoria stessa utilizzando le syscall mmap() e munmap(). 

Una mappa o mappatura (o mapping) puo' essere sostanzialmente di due tipi: 
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

Nota: Riguardo l'eliminazione del mapping.
      Allorquando un processe termina la propria esecuzione, il mapping viene
      cancellato automaticamente, comprese eventuali modifiche salvate su 
      disco nel caso in cui fosse stata utilizzata la protezione MAP_SHARED.

HEADER   : <sys/mman.h>
PROTOTYPE: int munmap(void *addr, size_t length);

Qualora si volesse eliminare il mapping manualmente, si dovra' invocare la
system call munmap(), che elimina il mapping specificato nel range compreso 
tra l'indirizzo 'addr' e il numero di byte 'length'. Per chiudere il file
mappato dovra' essere invocata specificatamente la syscall close().
Ritorna 0 in caso di successo, -1 altrimenti.

Nota: Una regione di memoria deve essere contrassegnata o MAP_PRIVATE o 
      MAP_SHARED, tutto il resto e' opzionale e non vincolante.

MAP_ANON non comporta file su disco, alloca la memoria per l'utilizzo privato
del processo, e' come se si utilizzasse la malloc() in un certo senso.

*/


int main(int argc, char *argv[]) {
    void *addr;
    size_t size = 4096;

    addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    
    if (addr == MAP_FAILED) {
        fprintf(stderr, "Err.(%d) mmap(): %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
