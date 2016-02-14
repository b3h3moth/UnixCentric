#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

/* Il kernel linux consente ad ogni processo di mappare un file su disco 
direttamente in memoria, creando in tal modo una relazione tra i byte del file
su disco e i byte della memoria. 

Il vantaggio principale di questa tecnica e' che i file mappati in memoria sono
piu' veloci di quelli su disco; inoltre i dati sono condivisi, per cui processi
multipli possono accedere alle medesime informazioni.

La funzione mmap() consente il mapping di un file:

HEADER   : <sys/mman.h>
PROTOTYPE: void *mmap(void *addr, size_t length, int prot, int flags,
                      int fd, off_t offset);


*/

int main(void) {
    return(EXIT_SUCCESS);
}
