#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(void) {
    /* Prima di qualsiasi altra funzione, la libreria dovrebbe essere 
    inizializzata, questa tuttavia pur essendo una procedura raccomandata
    e' superata dalla maggior parte delle funzione stesse che lo fanno
    automaticamente. */
    if (sqlite3_initialize() == SQLITE_OK)
        printf("Library \'%s\' initialized\n", sqlite3_libversion());

    sqlite3_shutdown();
    return(EXIT_SUCCESS);
}
