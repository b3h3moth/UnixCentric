#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* Il linguaggio C consente di definire funzioni che consentono un numero
arbitrario di parametri, tipicamente sono le funzioni I/O; in tali funzioni il
numero arbitrario di parametri si indica nel prototipo con l'ellissi "..." e
deve sempre seguire obbligatoriamente un parametro fisso.

L'header di riferimento e' <stdarg.h> che contiene una serie di utilities per 
la standardizzazione dell'utilizzo delle funzioni con un numero arbitrario di 
parametri.

Le utilities fornite da <stdarg.h> (dipendenti dal sistema utilizzato):
- il tipo  'va_list' (typedef char *va_list);
- la macro 'va_start';
- la macro 'va_arg';
- la macro 'va_end';
- la macro 'va_copy' (da c99).

Esse in realta' sono delle macro che si comportano come funzioni, ovvero che
accettano argomenti (function-like macro).
*/

double my_sum(int n, ...);

int main(int argc, char *argv[]) {
    double w = 10.5;
    double x = 20.5;
    double y = 30.5;
    double z = 40.5;

    printf("w            = %f\n", my_sum(1, w));
    printf("w + x        = %f\n", my_sum(2, w, x));
    printf("x + x + y    = %f\n", my_sum(3, w, x, y));
    printf("x + x + y  z = %f\n", my_sum(4, w, x, y, z));

    return(EXIT_SUCCESS);
}

/* Prototipo della funzione my_sum(), che prende un numero arbitrario di 
parametri del tipo 'double' e ne restituisce la somma. L'ellissi come ultimo
argomento indica che si tratta di una 'variadic function' */
double my_sum(int n, ...) {
    /* Conta gli argomenti */
    int arg;
    /* Somma gli argomenti */
    double sum = 0.0;
    /* Lista degli argomenti */
    va_list ap;

    /* Inizializzazione della lista degli argomenti */
    va_start(ap, n);

    for (arg=0; arg<n; ++arg)
        sum += va_arg(ap, double);

    /* Chiusura della lista di argomenti */
    va_end(ap);

    return(sum);
}
