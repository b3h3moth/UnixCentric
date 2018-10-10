#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Nello standard C89 una variabile doveva essere dichiarata prima di
    essere utilizzata e non dovevano esserci altri tipi di istruzioni tra di
    esse;, dallo standard C99 invece una variabile puo' essere dichiarata
    ovunque.

    Si compili il seguente codice con:
    -gcc -pedantic -Wall -std=c89
    -gcc -pedantic -Wall -std=c99

    Naturalmente anche lo standard C11 (-std=c11) compila con la nuova regola
    stabilita dallo standard C99.
    */
    int first = 10;

    printf("%d\n", first);

    /* Con -std=c89 si avra'il seguente warning:
    warning: ISO C90 forbids mixed declarations and code [-Wpedantic] */
    int second = 20;
    printf("%d\n", second);

    /* Con -std=c89 si avra'il seguente error:
    error: for loop initial declarations are only allowed in C99 or C11 mode */
    for (int i=0; i<first; i++)
        printf("%d ", i);

    return(EXIT_SUCCESS);
}
