#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *names[] = {
        "francesca",
        "claudia",
        "giovanna",
        "isabella",
        "x",
        "deborah",
        NULL
    };

    char new_name[] = "rossella";

    /* Il modo migliore per copiare una stringa allorquando si lavora con
    array of pointers e' di salvare semplicemente il puntatore della nuova
    stringa */
    names[4] = &str[0];

    return(EXIT_SUCCESS);
}
