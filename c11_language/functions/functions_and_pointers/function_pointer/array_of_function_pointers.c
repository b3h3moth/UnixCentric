#include <stdio.h>
#include <stdlib.h>

typedef int (*fp)(int, int);

// Dichiarazione di un array di puntatori funzione
fp operation[128] = {NULL};
// Istruzione equivalente: int (*operation[128])(int, int) = { NULL };

// Function Prototypes
int sum(int val1, int val2);
int sub(int val1, int val2);
int mol(int val1, int val2);
fp select(char op);
int eval(char op, int val1, int val2);
void inizialize_op(void);

/* Lo scopo del programma e' di creare un esempio usabile di array di puntatori
a funzione */

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

// Moltiplica due interi
int mol(int val1, int val2) {
    return val1 * val2;
}

// Assegna la funzione adatta a ciascun operatore
void inizialize_op(void) {
    operation['+'] = sum;
    operation['-'] = sub;
    operation['*'] = mol;
}

/* Se op contiene il segno '+' ritorna la funzione sum(), se invece contiene
il segno '-' ritorna la funzione sub() */
fp select(char op) {
    switch(op) {
        case '+': return sum;
        case '-': return sub;
        case '*': return mol;
    }

    return 0;
}

// Valuta i parametri a seconda del contesto
int eval(char op, int val1, int val2) {
    fp operation = select(op);
    return operation(val1, val2);
}
