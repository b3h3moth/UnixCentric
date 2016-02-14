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

Il file aperto associato al file descriptor 'fd' e' mappato a partire dall'
indirizzo 'addr', se 'addr' dovesse valere NULL sara' il kernel stesso a 
definire l'indirizzo dal quale iniziare la mappatura. La dimensione del file da
mappare e' definita da 'length'. La protezione del range di memoria e'
stabilito da 'prot', i cui valori riguardano lettura 'PROT_READ', scrittura 
'PROT_WRITE', esecuzione 'PROT_EXEC' e accesso non consentito 'PROT_NONE'. Il
tipo di memoria impostato mediante la variabile intera 'flags'.

La funzione mmap() restituisce un puntatore alla regione di memoria associata
in caso di successo, -1 altrimenti.

*/

int main(void) {
    return(EXIT_SUCCESS);
}
