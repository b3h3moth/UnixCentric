#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/* Se un thread all'interno di un processo dovesse invocare exit(), _Exit(), 
oppure _exit(), l'intero processo sara' terminato, per cui e' necessario un 
meccanismo meno invasivo di terminazione; i thread contemplano 3 modalita' di 
terminazione del loro flusso di esecuzione, senza peraltro terminare anche il 
processo:
1 - Un thread semplicemente ritorna dalla routine di avvio;
2 - Un thread puo' essere cancellato da un altro thread nello stesso processo;
3 - Un thread puo' invocare la funzione pthread_exit().




HEADER    : <pthread.h>
PROTOTYPE : void pthread_exit(void *ret_val);
SEMANTICS : La funzione pthread_exit() termina il thread chiamante e ritorna il
            relativo valore mediante la variabile 'retval'.
RETURNS   : Questa funzione non ritorna
--------------------------------------------------------------------------------
*/

int main(void) {
    
    return(EXIT_SUCCESS);
}
