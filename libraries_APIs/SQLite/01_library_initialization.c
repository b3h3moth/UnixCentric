#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(void) {

    /* Prima di qualsiasi altra funzione, la libreria dovrebbe essere 
    inizializzata, questa pratica tuttavia pur essendo raccomandata
    e' superata dalla maggior parte delle 'core API' stesse che lo fanno
    automaticamente. */
    
    if (sqlite3_initialize() == SQLITE_OK)
        printf("Library \'%s\' initialized\n", sqlite3_libversion());

    // Rilascia tutte le risorse allocate nell'inizializzazione
    if (sqlite3_shutdown() == SQLITE_OK)
        printf("Library freed\n");

    return(EXIT_SUCCESS);
}
