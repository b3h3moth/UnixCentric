#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/resource.h>

/* Ciascun processo e' in grado sia di ottenere sia di settare i limiti delle
proprie risorse, in particolare la funzione getrlimit() viene utilizzata per
l'ottenimento delle informazioni mentre la funzione setrlimit() e' deputata
al settaggio.

Entrambe le funzioni puntano alla struttura rlimit:
struct rlimit {
    rlim_t rlim_cur;    // limite corrente; soft limit
    rlim_t rlim_max;    // limite massimo; hard limit
};

HEADER    : <sys/resource.h>
PROTOTYPE : int getrlimit(int resource, struct rlimit *prl);
SEMANTICS : la funzione getrlimit() ottiene informazioni su 'resource', che
            punta alla struttura di tipo rlimit *prl.
RETURNS   : 0 in caso di successo, non zero in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    return(EXIT_SUCCESS);
}
