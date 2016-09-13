#include <stdio.h>
#include <stdlib.h>

int sum(const int *n1, const int *n2);

/* Lo scopo del programma e' di utilizzare come parametro di funzione un
puntatore a const */

int main(void) {
    int val1 = 100;
    int val2 = 200;
    int res = sum(&val1, &val2);

    printf("Result is: %d\n", res);

    return(EXIT_SUCCESS);
}

int sum(const int *n1, const int *n2) {
    return *n1 + *n2;
}

/* Error: assignment of read-only location
int sum(const int *n1, const int *n2) {
    return *n1 = *n1 + *n2;
}
*/
