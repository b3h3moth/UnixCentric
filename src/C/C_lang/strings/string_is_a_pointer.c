#include <stdio.h>
#include <stdlib.h>

int main(void) {

    /* E' possibile verificare che una stringa, in C, e' essa stessa un
    puntatore */
    char *p =  "A String in C is a Poiner itself";

    for (int i = 0; *(p + i) != '\0'; ++i)
        printf("%c",  *(p + i) );

    // Non valido con un array numerico.

    return(EXIT_SUCCESS);
}
