#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* La notazione scientifica o forma standard e' un sistema che sfrutta il 
    concetto di esponente al fine di sintetizzare la rappresentazione di un 
    valore numerico. Un numero con 'n' zeri dopo di esso equivale al
    medesimo numero moltplicato per 10^n, ne consegue che risulta essere 
    particolarmente efficace nella rappresentazione compatta di numeri o molto
    grandi o molto piccoli

    La costante di Avogadro ad esempio e' 6,022 x 10^23, molto piu' comodo di
    602200000000000000000000000.

    Il linguaggio C utilizza un formato ben preciso in tal senso, una E -
    maiuscola o minuscola - prima dell'esponente. */
    float const avogadro = 6.022e23;
    
    return(EXIT_SUCCESS);
}
