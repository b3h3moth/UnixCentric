#include <stdio.h>
#include <stdlib.h>

/* Lo standard c99 (iso9899:1999) ha introdotto il qualificatore restrict.

Il qualificatore restrict riguarda solo i puntatori, da cui restricted pointer.

Se un puntatore 'ptr' dovesse puntare a un oggetto, e se tale oggetto fosse
stato modificato in seguito, allora l'oggetto non sara' accessibile in nessun
altro modo se non mediante il puntatore 'ptr'. Tuttavia l'oggetto sara'
accessibile in alcuni quasi, quali:
- con un ulteriore puntatore al medesimo oggetto;
- ptr che punti a una variabile con nome.
*/

int main(void) {
    int val = 10;

    /* restrict deve essere posto prima dell'identificatore del puntatore,
    poiche' si occupa di qualificare il puntatore stesso e non l'oggetto cui
    ptr punta */
    int * restrict ptr1 = &val;
    int *ptr2 = &val;

    *ptr1 = 20;
    *ptr2 = 30;

    return(EXIT_SUCCESS);
}
