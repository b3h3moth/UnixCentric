#include <stdio.h>
#include <stdlib.h>

/* Allorquando si lavora con un programma che contiene la libreria SQLite e in 
altri contesti dove serve una configurazione della libreria specifica, 
puo' risultare utile avere una configurazione globale della libreria stessa. 
A tale scopo e' stata implemenata l'interfaccia sqlite3_config(int, ...).

Nota: Nella maggior parte dei casi la configurazione di default risulta essere
      piu' che sufficiente.
 
L'interfaccia sqlite3_config() deve essere invocata prima dell'inizializzazione
della libreria con sqlite3_initialize() e dopo lo shutdown della stessa 
mediante sqlite3_shutdown(), altrimensi sara' resituito l'errore SQLITE_MISUSE.

Il primo argomento della funzione e' un intero che determina le opzioni di
configurazione della libreria SQLite, gli argomenti successivi dipendono dal 
primo argomento. Allorquando l'opzione di configurazione va a buon fine 
ritorna SQLITE_OK, altrimento un codice d'errore.
*/

int main(void) {
    return(EXIT_SUCCESS);
}
