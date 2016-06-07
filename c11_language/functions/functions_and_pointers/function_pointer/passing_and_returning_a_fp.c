#include <stdio.h>
#include <stdlib.h>

/* Nuovo tipo di dato 'fp', un puntatore a funzione che accetta due parametri
di tipo intero, e ritorna un intero */
typedef int (*fp)(int, int);

// Functinn Prototype
int sum(int val1, int val2);
int sub(int val1, int val2);
int operation(fp calc, int val1, int val2);

int main(void) {
    return(EXIT_SUCCESS);
}

// Somma due interi
int sum(int val1, int val2) {
    return val1 + val2;
}

// Sottrae due interi
int sub(int val1, int val2) {
    return val1 - val2;
}

int operation(fp calc, int val1, int val2) {
    return calc(val1, val2);
}
