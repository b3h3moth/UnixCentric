#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef size_t (*fptr)(char *);

// Function Prototype
size_t process_string(char *str);

/* Lo scopo del programma e' l'utilizzo di puntatori a funzione per gestire
talune stringhe inviando in output la lunghezza e la stringa stessa. */

int main(void) {
    /* Una prima dichiarazione di puntatore a funzione senza l'ausilio
    del tipo creato con la typedef */
    size_t (*fpstrlen)(char *);
    // La dichiarazione di fpstrlen2 utilizzando il nuovo tipo
    fptr fpstrlen2;

    char *pstr[] = {
        "The art of C programming",
        "C++ is a good choice for OOP",
        "Functional programming is beautiful and Lisp is a good think",
        "AWK was initially developer in 1977 ...",
        "...by Aho, Weinberger and Kernighan",
        "UNIX is an ideal development environment"
    };

    // Copia l'indirizzo della funzione process_string()
    fpstrlen = process_string;      // Consigliata
    fpstrlen2 = &process_string;    // Equivalente, non consigliata

    /* Nella prima chiamata non e' stato necessario inserire
    l'operatore 'address-of', poiche' il compilatore l'avrebbe comunque
    ignorato; nella seconda chiamata invece è stato utilizzato, ma resta una
    pratica non consigliata, come peraltro sottolineato subito dopo la
    chiamata. */

    /* Stampa le stringhe dell'array di puntatori, invocando prima
    fpstrlen() e successivamente fpstrlen2() */
    for (int i = 0; i < 3; i++)
        printf("The length of \"%s\" is: %ld\n", pstr[i], fpstrlen(pstr[i]));
    // Codice ripetitivo usato a scopo prettamente didattico
    for (int i = 3; i < 6; i++)
        printf("The length of \"%s\" is: %ld\n", pstr[i], fpstrlen2(pstr[i]));

    return(EXIT_SUCCESS);
}

size_t process_string(char *str) {
    size_t i=0;

    while (*str++)
        i++;

    return i;
}
