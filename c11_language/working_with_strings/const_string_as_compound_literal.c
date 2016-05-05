#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Inizializzazione di una costante stringa, o meglio, di un puntatore 
    a una costante carattere */
    const char *str = (const char[]){"Take a Walk on The Wild Side"};

    // Stampa l'intera stringa puntando al primo carattere
    printf("%s\n", str);

    // Stampa char by char
    while (*str != '\0')
        printf("%c", *str++);

    return(EXIT_SUCCESS);
}
