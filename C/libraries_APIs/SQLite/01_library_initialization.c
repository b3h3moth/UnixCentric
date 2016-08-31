#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(void) {

    /* Prima di invocare una qualsiasi funzione, la libreria dovrebbe essere 
    inizializzata, da notare che questa pratica pur essendo raccomandata
    e' superata dalla maggior parte delle 'core APIs' che lo fanno
    automaticamente, come ad esempio la funzione sqlite3_open().
    
    A rigor di logica quindi non dovrebbe essere utilizzata. Tuttavia non e'
    cosi', poiche' per garantire la massima portabilita' dei programmi sarebbe 
    il caso di inizializzare la libreria esplicitamente, inoltre i futuri
    rilasci di SQLite lo prevederanno, quindi e' buona norma farlo. 
    
    Pertanto, nei programmi scritti nel presente repository la libreria sara'
    inizializzata e rilasciata mediante le appositie funzioni. */
    
    if (sqlite3_initialize() == SQLITE_OK)
        printf("Library \'%s\' initialized\n", sqlite3_libversion());

    // Rilascia tutte le risorse allocate nell'inizializzazione
    if (sqlite3_shutdown() == SQLITE_OK)
        printf("Library freed\n");

    return(EXIT_SUCCESS);
}
