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

    int second = 20;
    printf("%d\n", second);

    for (int i=0; i<first; i++)
        printf("%d ", i);

    return(EXIT_SUCCESS);
}
