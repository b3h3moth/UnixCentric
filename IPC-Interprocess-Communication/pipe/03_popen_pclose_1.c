#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* Il lavoro fatto dalla funzione pipe() viene svolto interamente dalle funzioni
popen() e pclose().


HEADER    : <stdio.h>
PROTOTYPE : FILE *popen(const char *cmdstring, const char *type);
SEMANTICS : La funzione popen() apre una pipe, crea un nuovo processo mediante
            una fork ed esegue 'cmdstring' su una exec e ritorna un puntatore 
            al file I/O standard; se 'type' equivale a r (read) il puntatore 
            sara' connesso allo standard output di 'cmdstring', se 'type' sara'
            w il puntatore sara' connesso allo standard input di 'cmdstring'.
RETURNS   : Un puntatore in caso di successo, NULL in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {


    return(EXIT_SUCCESS);
}
