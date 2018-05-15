#include <stdio.h>
#include <stdlib.h>

typedef int (*fp)(int, int);

// Dichiarazione di un array di puntatori funzione
fp fparr[4] = {NULL};
// Istruzione equivalente: int (*operation[3])(int, int) = { NULL };

// Function Prototypes
int sum(int val1, int val2);
int sub(int val1, int val2);
int mol(int val1, int val2);
int dv(int val1, int val2);
int eval(int op, int val1, int val2);
void initialize_op(void);

/* Lo scopo del programma e' di creare un esempio usabile di array di puntatori
a funzione */

int main(void) {
    initialize_op();
    printf("100+20=%d\n", eval('+', 100, 20));
    printf("100-20=%d\n", eval('-', 100, 20));
    printf("100*20=%d\n", eval('*', 100, 20));
    printf("100/20=%d\n", eval('/', 100, 20));
    printf("100/0=%d\n",  eval('/', 100, 0));
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

int dv(int val1, int val2) {
    return (val2 == 0) ? 0 : (val1 / val2);
}

// Assegna la funzione adatta a ciascun operatore
void initialize_op(void) {
    fparr['+'] = sum;
    fparr['-'] = sub;
    fparr['*'] = mol;
    fparr['/'] = dv;
}

// Valuta i parametri a seconda del contesto
int eval(int op, int val1, int val2) {
    fp operation;
    operation = fparr[op];
    return operation(val1, val2);
}
