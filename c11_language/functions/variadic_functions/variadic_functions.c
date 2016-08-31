#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* Il linguaggio C permette di definire funzioni che consentono un numero
arbitrario di parametri, tipicamente sono le funzioni di I/O.

Nota: Il numero arbitrario di parametri si indica nel prototipo di funzione
      con l'ellissi "..." e deve seguire obbligatoriamente un parametro fisso.

L'header di riferimento e' <stdarg.h> che contiene una serie di utilities per 
la standardizzazione della procedura.

Le utilities fornite da <stdarg.h> - dipendenti dal sistema utilizzato - 
lavorano con il tipo di dato 'va_list' - typedef char *va_list):
- la macro 'va_start';
- la macro 'va_arg';
- la macro 'va_end';
- la macro 'va_copy' (ereditato da c99).

Esse in realta' sono delle macro che si comportano come funzioni, ovvero che
accettano argomenti (function-like macro).
*/

double addition(int n, ...);

int main(int argc, char *argv[]) {
    double w = 10.5;
    double x = 20.5;
    double y = 30.5;
    double z = 40.5;

    /* Il primo argomento indica quanti argomenti saranno utilizzati dalla 
    funzione addition(), ovvero 1, 2, 3 e infine 4 */
    printf("w = %f\n", addition(1, w));
    printf("w + x = %f\n", addition(2, w, x));
    printf("x + x + y = %f\n", addition(3, w, x, y));
    printf("x + x + y + z = %f\n", addition(4, w, x, y, z));

    return(EXIT_SUCCESS);
}

/* Prototipo della funzione addition(), che prende un numero arbitrario di 
parametri del tipo 'double' e ne restituisce la somma. L'ellissi come ultimo
argomento indica che si tratta di una 'variadic function' */
double addition(int n, ...) {
    // Conta gli argomenti
    int arg;
    double result = 0.0;

    /* La variabile 'ap' di tipo 'va_list' conterra' di volta in volta un
    rierimento all'argomento variabile; 'ap' sta per 'argument pointer' */
    va_list ap;

    // Inizializza 'ap' in modo tale che punti al primo argomento anonimo
    va_start(ap, n);

    /* va_arg() ricava uno alla volta tutti gli argomenti anonimi da 
    processare, essa inoltre modifica la variabile 'ap' in modo tale che punti
    successivo argomento, e cosi' via */
    for (arg=0; arg<n; ++arg)
        result += va_arg(ap, double);

    /* Operazioni di pulizia di 'ap', solitamente viene liberata la memoria
    per consentire successive inizializzazioni */
    va_end(ap);

    return(result);
}
