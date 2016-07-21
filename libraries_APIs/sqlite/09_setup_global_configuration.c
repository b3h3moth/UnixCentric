#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Allorquando si lavora con un programma che contiene la libreria SQLite e in 
altri contesti dove serve una configurazione della libreria specifica, 
puo' risultare utile avere una settaggio globale della libreria stessa. 
A tale scopo e' stata implemenata l'interfaccia sqlite3_config(int, ...).

Nota: Nella maggior parte dei casi la configurazione di default risulta essere
      piu' che sufficiente.
 
L'interfaccia sqlite3_config() deve essere invocata prima dell'inizializzazione
della libreria con sqlite3_initialize() e dopo lo shutdown della stessa 
mediante sqlite3_shutdown(), altrimenti sara' resituito l'errore SQLITE_MISUSE.

Il primo argomento dell'interfaccia e' un intero che determina le opzioni di
configurazione della libreria SQLite, i successivi argomenti invece dipendono
dal primo, ovvero dal valore intero che e' stato inserito. 

Valore di ritorno: Allorquando l'opzione di configurazione dovesse andare a 
buon fine ritornebbe SQLITE_OK, altrimenti un codice d'errore diverso da zero.

Nota: E' consentito settare solo un'opzione di configurazione, le restanti 
      saranno mantenute ai valori di default.
*/

int main(void) {
    /* Determina l'opzione di configurazione relativa al multithreading, che
    non necessita peraltro di ulteriore argomento */
    sqlite3_config(SQLITE_CONFIG_MULTITHREAD);

    // Inizializzazione della libreria
    if (sqlite3_initialize() == SQLITE_OK)
        printf("Library: \'%s\' initialized\n", sqlite3_libversion());

    // Rilascio delle risorse
    if (sqlite3_shutdown() == SQLITE_OK)
        printf("Library: freed\n");

    return(EXIT_SUCCESS);
}
