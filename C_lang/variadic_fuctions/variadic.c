#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* Il linguaggio C consente di definire funzioni che consentono un numero
arbitrario di parametri, tipicamente sono le funzioni I/O; in tali funzioni il
numero arbitrario di parametri si indica nel prototipo con l'ellissi "..." e
deve sempre seguire obbligatoriamente un parametro fisso.

L'header di riferimento e' <stdarg.h> che contiene una serie di utilities per 
la standardizzazione sulll'uso delle funzioni con un numero arbitrario di 
parametri.

Le utilities fornite da <stdarg.h> (dipendenti dal sisistema utilizzato):
- typedef char * va_list;
- va_start();
- va_arg();
- va_end();
- va_copy().
*/

/* Prototipo della funzione my_sum(), che prende un numero arbitrario di 
parametri del tipo 'double' e ne restituisce la somma. L'ellissi come ultimo
argomento indica che si tratta di una 'variadic function' */
void my_sum(int n, ...);

int main(int argc, char *argv[]) {
    double w = 10.5;
    double x = 20.5;
    double y = 30.5;
    double z = 40.5;

    printf("w            = %f\n", my_sum() );
    printf("w + x        = %f\n", my_sum() );
    printf("x + x + y    = %f\n", my_sum() );
    printf("x + x + y  z = %f\n", my_sum() );

    return(EXIT_SUCCESS);
}

void my_sum(int num, ...) {
    /* Conta gli argomenti */
    int arg;
    /* Somma gli argomenti */
    double sum;
    /* Lista degli argomenti */
    va_list ap;

    /* Inizializzazione della lista degli argomenti */
    va_start(ap, n);

    va_end(ap);

    return(sum);
}

