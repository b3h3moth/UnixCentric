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

Le utilities fornite da <stdarg.h> - dipendenti dal sistema utilizzato - 
lavorano con il tipo di dato 'va_list' - typedef char *va_list):
- la macro 'va_start';
- la macro 'va_arg';
- la macro 'va_end';
- la macro 'va_copy' (ereditato da c99).

Esse in realta' sono delle macro che si comportano come funzioni, ovvero che
accettano argomenti (function-like macro).
*/

double my_sum(int n, ...);

int main(int argc, char *argv[]) {
    double w = 10.5;
    double x = 20.5;
    double y = 30.5;
    double z = 40.5;

    /* Il primo argomento indica quanti argomenti saranno utilizzati dalla 
    funzione my_sum(), ovvero 1, 2, 3 e infine 4 */
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
    // Conta gli argomenti
    int arg;
    double sum = 0.0;

    va_list ap;

    // Inizializza 'ap' in modo tale che punti al primo argomento anonino
    va_start(ap, n);

    // va_arg() ricava uno alla volta tutti gli argomenti anonimi
    for (arg=0; arg<n; ++arg)
        sum += va_arg(ap, double);

    // Operazioni di pulizia
    va_end(ap);

    return(sum);
}
