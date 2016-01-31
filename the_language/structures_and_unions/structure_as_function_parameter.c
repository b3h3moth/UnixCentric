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
    return(EXIT_SUCCESS);
}

// Inizializza e restituisce la struttura point
struct point init(int x, int y) {

/* Somma i membri delle strutture sp1 e sp2, e restituisce il risultato sotto
forma di struttura di tipo point */
struct point sum(struct point sp1, struct point sp2) {

// Assegna ai membri della struttura puntata da *sptr valori random
void random(struct point *sptr) {
