#include <stdio.h>
#include <stdlib.h>

// Lo scopo del programma e' di scrivere una funzione che ritorni un puntatore

int *create_array(

int main(void) {
    int num1 = 20;
    int num2 = 30;

    int *val = get_max(&num1, &num2);

    printf("Val: %d\n", *val);

    return(EXIT_SUCCESS);
}

int *get_max(int *x, int *y) {
    if (*x > *y)
        return x;
    else 
        return y;
}
