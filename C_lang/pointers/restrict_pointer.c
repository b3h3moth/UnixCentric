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
occupa di qualificare il puntatore stesso e non l'oggetto cui ptr punta */

int f(int * restrict p1, int * restrict *p2);

int main(void) {
    int * restrict px;
    int * restrict py;

    px = malloc(sizeof(int));
    *px = 10;
    py = px;

    printf("%d\n", *px);

    // In questo caso si puo' verificare un comportamento indefinito
    *py = 20;

    printf("%d\n", *py);

    return(EXIT_SUCCESS);
}

int f(int * restrict p1, int * restrict *p2) {
    *p1 = 100;
    *p2 = 200;

    return *p1 + *p2;
}
