#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*
Thread addizionali possono essere creati mediante la funzione pthread_create();
da notare che il tipo di dato dei thread e' definito come pthread_t, un intero
non negativo simile all'analogo pid_t relativo pero' ai processi.

HEADER    : <pthread.h>
PROTOTYPE : int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                               void *(*start_routine) (void *), void *arg);
SEMANTICS : La funzione pthread_create() prende 4 argomenti:
            - pthread_t *thread, e' un puntatore a pthread_t;
            - pthread_attr_t *attr, gli attributi del nuovo thread, qualora non
              si volessero modificare, sara' sufficiente inserire NULL;
            - void *(*start_routine) (void *), il codice da eseguire. Trattasi 
              di un puntatore a funzione che prende un puntatore a void e
              restituisce un puntatore a void;
            - void *arg, sono gli eventuali argomenti da passare, qualora non
              si volessero passare argomenti, sara' sufficiente inserire NULL.
RETURNS   : 0 in caso di successo, numero di errore in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    return(EXIT_SUCCESS);
}
       #include <pthread.h>

