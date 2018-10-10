#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char str[] = "Take a walk on the wild side";
    char *p;

    /* Così facendo si allochera' la memoria necessaria a contenere l'oggetto
    a cui 'p' puntera' */
    p = malloc(sizeof(*p));

    // Ora 'p' punta a 'str', pertanto saranno allocati sizeof(str) byte
    p = str;

    printf("%s\n", p);

    return(EXIT_SUCCESS);
}
