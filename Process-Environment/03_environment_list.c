#include <stdio.h>
#include <stdlib.h>

/*
 * Array di stringhe che permette di verificare le variabili di ambiente del
 * sistema
 */

extern char** environ;

int main(void) {
    char** var;

    for (var = environ; *var != NULL; ++var) {
		printf("%s\n", *var);
    }

    return(EXIT_SUCCESS);
}

