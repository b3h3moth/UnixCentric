#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
    int sum;
};

// Function prototypes
struct point init(int x, int y);
struct point sum(struct point sp1, struct point sp2);
void random(struct point *sptr);

int main(void) {

    struct point my_sp;

    my_sp = init(10, 20);
    printf("my_sp.x = %d, my_sp.y = %d\n",my_sp.x, my_sp.y);
    
    return(EXIT_SUCCESS);
}

// Inizializza e restituisce la struttura point
struct point init(int val1, int val2) {
    
    /* Un modo potrebbe essere di creare una struttura, inizializzarne i
    membri e infine restuirla al chiamante:
    
    struct point temp;
    temp.x = val1;
    temp.y = val2;
    
    return temp; 

    Oppure si fa ritornare direttamente una struttura anonima i cui membri 
    saranno inizializzati mediante, per l'appunto, gli inizializzatori 
    designati (designated initializers) */

    return (struct point) {.x = val1, .y = val2};
}


/* Somma i membri delle strutture sp1 e sp2, e restituisce il risultato sotto
forma di struttura di tipo point */
struct point sum(struct point sp1, struct point sp2) {
}

// Assegna ai membri della struttura puntata da *sptr valori random
void random(struct point *sptr) {
}
