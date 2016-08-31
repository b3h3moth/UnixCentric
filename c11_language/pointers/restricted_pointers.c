#include <stdio.h>
#include <stdlib.h>

/* Lo standard c99 (iso9899:1999) ha introdotto il qualificatore restrict.

Il qualificatore restrict riguarda solo i puntatori, da cui restricted pointer.

Se un puntatore 'ptr' dovesse puntare a un oggetto, e se tale oggetto fosse
stato modificato in seguito, allora l'oggetto non sara' accessibile in nessun
altro modo se non mediante il puntatore 'ptr'. Tuttavia l'oggetto sara'
accessibile in taluni casi, quali:
- con un ulteriore puntatore al medesimo oggetto;
- con ptr che punti a una variabile con nome.

restrict deve essere posto prima dell'identificatore del puntatore, poiche' si
occupa di qualificare il puntatore stesso e non l'oggetto cui ptr punta.

restrict consente l'ottimizzazione.*/

void f(int *x, int *y, int *restrict p);

int main(void) {
    int val1 = 100;
    int val2 = 200;

    f(&val1, &val2, &val1);
    printf("Result: %d, %d\n", val1, val2);

    // Reset values
    val1 = 50;
    val2 = 75;

    f(&val1, &val2, &val1);
    printf("Result: %d, %d\n", val1, val2);

    return(EXIT_SUCCESS);
}

void f(int *x, int *y, int *restrict p) {
    *x += *p;
    *y += *p;
}
