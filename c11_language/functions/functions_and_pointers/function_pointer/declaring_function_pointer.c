#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototype
size_t process_string(char *str);

/* Lo scopo del programma e' di dichiarare un puntatore a funzione, dopodiche'
utilizzarlo salvando al suo interno l'indirizzo di un'altra funzione. */

int main(void) {
    // Dichiara il puntatore a funzione fpstrlen
    size_t (*fpstrlen)(char *);
    char *pstr[] = {
        "The art of C programming",
        "C++ is a good choice for OOP",
        "Functional programming is beautiful and Lisp is a good think",
        "AWK was initially developer in 1977 ...",
        "...by Aho, Weinberger and Kernighan",
        "UNIX is an ideal development environment"
    };

    // Copia l'indirizzo della funzione process_string() in fpstrlen
    fpstrlen = process_string;

    /* Non e' stato necessario inserire l'operatore 'address-of', poiche' il
    compilatore l'avrebbe comunque ignorato, pertanto la chiamata
    fpstrlen = &process_string; 
    e' equivalente, ma non consigliata */

    // Invoca fpstrlen() su ogni stringa dell'array di puntatori
    for (int i = 0; i < (sizeof(pstr)/sizeof(pstr[0])); i++)
        printf("The length of \"%s\" is: %d\n", pstr[i], fpstrlen(pstr[i]));
    
    return(EXIT_SUCCESS);
}

size_t process_string(char *str) {
    size_t i=0;

    while (*str++)
        i++;

    return i;
}
