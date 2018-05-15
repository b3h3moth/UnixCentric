#include <stdio.h>
#include <stdlib.h>

/* Nuovo tipo di dato 'fp', un puntatore a funzione che accetta due parametri
di tipo intero, e ritorna un intero */
typedef int (*fp)(int, int);

// Function Prototypes
int sum(int val1, int val2);
int sub(int val1, int val2);
int mol(int val1, int val2);
int division(int val1, int val2);
fp select_symbol(char op);
int eval(char op, int val1, int val2);

// Lo scopo del programma e' di creare esempio usabile di puntatore a funzione

int main(void) {
    printf("sum: %d\n", eval('+', 20, 10));
    printf("sub: %d\n", eval('-', 20, 10));
    printf("mol: %d\n", eval('*', 20, 10));
    printf("div: %d\n", eval('/', 20, 10));

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

// Moltiplica due interi
int mol(int val1, int val2) {
    return val1 * val2;
}

// Divide due interi (molto molto basic)
int division(int val1, int val2) {
    return val1 / val2;
}

/* Se op contiene il segno:
'+' ritorna la funzione sum();
'-' ritorna la funzione sub();
'*' ritorna la funzione mol();
'/' ritorna la funzione division();
*/
fp select_symbol(char op) {
    switch(op) {
        case '+': return sum;
        case '-': return sub;
        case '*': return mol;
        case '/': return division;
    }
    return 0;
}

// Valuta i parametri a seconda del contesto
int eval(char op, int val1, int val2) {
    fp operation = select_symbol(op);
    return operation(val1, val2);
}
