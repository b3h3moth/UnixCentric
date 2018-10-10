#include <stdio.h>
#include <stdlib.h>

#define VECSIZE(x) ((int)sizeof(x) / sizeof(x[0]))

// Prototipi
int make_operations(int val1, int val2, int (*func)(int, int));
// A supporto della funzione make_operations().
int addition(int val1, int val2);
int subtraction(int val1, int val2);
int multiplication(int val1, int val2);
int division(int val1, int val2);

/* Lo scopo del programma e' la creazione della funzione generica 
make_operations(), in grado di eseguire diverse operazioni tra due valori 
mediante l'utilizzo di una ulteriore funzione passata come argomento. */

int main(void) {

    /* Un vettore di puntatori a funzione con due parametri di tipo int.
    Poiche' della funzione serve l'indirizzo e' lecito inserire il nome della
    funzione stessa sia con l'operatore 'address of, &', sia senza. */
    int (*operations_list[])(int, int) = { 
        &addition, &subtraction, multiplication, division };
   
    char *operations_name[] = { 
        "addition", "subtraction", "multiplication", "division" };

    for (int i=0; i<VECSIZE(operations_list); i++) {
        printf("(%14s %d %d) = %d\n", operations_name[i], i, i, \
                make_operations(i, i, operations_list[i]));
    }

    return(EXIT_SUCCESS);
}

// Esegue una delle quattro operazioni
int make_operations(int val1, int val2, int (*func)(int, int)) {
    return (*func)(val1, val2);
}

int addition(int val1, int val2) {
    return (val1 + val2);
}

int subtraction(int val1, int val2) {
    return (val1 - val2);
}

int multiplication(int val1, int val2) {
    return (val1 * val2);
}

int division(int val1, int val2) {
    return (val1 / val2);
}
