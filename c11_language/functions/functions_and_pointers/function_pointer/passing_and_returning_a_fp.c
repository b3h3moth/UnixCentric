#include <stdio.h>
#include <stdlib.h>

/* Nuovo tipo di dato 'fp', un puntatore a funzione che accetta due parametri
di tipo intero, e ritorna un intero */
typedef int (*fp)(int, int);

// Functinn Prototype
int sum(int val1, int val2);
int sub(int val1, int val2);
fp select(char op);
int eval(char op, int val1, int val2);

int main(void) {
    printf("%d\n", eval('+', 10, 20));
    printf("%d\n", eval('-', 10, 20));

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
    
fp select(char op) {
    switch(op) {
        case '+': return sum;
        case '-': return sub;
    }

    return 0;
}

int eval(char op, int val1, int val2) {
    fp operation = select(op);
    return operation(val1, val2);
}
