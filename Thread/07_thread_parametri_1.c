#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

/* La funzione pthread_create() consente di passare uno o piu' argomenti alla
funzione che consente l'avvio di un thread, ci sono tuttavia alcuni accorgimenti
da considerare; anzitutto il caso piu' semplice, ossia un solo argomento, caso 
in cui non ci sono particolari avvertenze, se invece gli argomenti dovessero 
essere piu' d'uno si dovrebbe creare una struttura e all'interno della quale 
inserire i vari argomenti, infine passare l'intera struttura come argomento, 
questo faciliterebbe e di molto le cose.

HEADER    : 
PROTOTYPE : 
SEMANTICS : 
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    return(EXIT_SUCCESS);
}
