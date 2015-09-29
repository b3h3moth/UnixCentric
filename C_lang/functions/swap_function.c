#include <stdio.h>
#include <stdlib.h>

void swap(int *w, int *z);

int main(void) {
    int x = 10, y = 20;
    printf("before swap() x=%d - y=%d\n", x, y);

    // Si passano i puntatori x ed y alla funzione, i rispettivi indirizzi
    swap(&x, &y);

    printf(" after swap() x=%d - y=%d\n", x, y);

    return (EXIT_SUCCESS);
}

/* La funzione swap() scambia i valori delle variabili w, z, passate come
parametro */
void swap(int *w, int *z){
    int tmp = *w;
    *w = *z;
    *z = tmp;
}
