#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*
Quando un segnale viene catturato, la normale sequenza di istruzioni viene
interrotta, il processo tuttavia continua la propria esecuzione eseguendo
le istruzioni del signal handler; quando un signal handler ritorna, invece
di chiamare la funzione exit() o altre, il processo prosegue la normale sequenza
di istruzioni che stava eseguendo prima di essere "interrotto" dal segnale.

Cosa succede se nel corso della esecuzione di una system call viene catturato un
segnale e all'interno del signal handler si invocasse la medesima system call?
Ad esempio un processo sta utilizzando una malloc() che durante la propria
esecuzione riceve un segnale, il relativo signal handler chiama ancora una
malloc.

Reentrant functions, funzioni rientranti
----------------------------------------
SUS definisce una serie di funzioni che sono garantite essere rientranti.

Si dice rientrante una funzione che puo' essere interrotta in qualunque punto 
della sua esecuzione ed essere invocata una seconda volta da un altro thread di
esecuzione senza che questo comporti nessun problema nell'esecuzione della 
stessa; affinche' una funzione possa essere definita rientrante deve soddisfare
taluni specifici requisiti:

1 - Nessuna porzione del codice possa essere alterata durante l'esecuzione;

2 - Il codice non deve richiamare nessuna routine che non sia a sua volta 
    rientrante.

    Ad esempio, talune implementazioni delle funzioni malloc() e free() in 
    ANSI-C non lo sono e pertanto non dovrebbero essere utilizzate; nel caso
    in cui tuttavia dovesse essere necessario allocare memoria, si potrebbero
    adoperare le API di sistema rientranti, che offrono sicuramente maggiori
    garanzie.
   
3 - Il codice deve usare, se necessarie, solo variabili temporanee allocate 
    sullo stack;
   
4 - Il codice non deve modificare ne' variabili globali, ne' aree di memoria 
    condivise, ne' impiegare variabili locali statiche.

LISTA

Se una funzione non e' presente nella lista:
- E' perche' utilizza strutture dati statiche;
- E' una malloc() o una free();
- E' perche' fa parte della libreria I/O standard.

*/

int main(int argc, char *argv[]) {
    return(EXIT_SUCCESS);
}
