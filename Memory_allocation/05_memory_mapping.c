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

*/

int main(void) {
    return(EXIT_SUCCESS);
}
