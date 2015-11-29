#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* La notazione scientifica o forma standard e' un sistema che sfrutta il 
    concetto di esponente al fine di sintetizzare la rappresentazione di un 
    valore numerico. Un numero con 'n' zeri dopo di esso equivale al
    medesimo numero moltplicato per 10^n, ne consegue che risulta essere 
    particolarmente efficace nella rappresentazione compatta di numeri o molto
    grandi o molto piccoli

    La costante di Avogadro ad esempio e' all'incirca 6 x 10^23, molto piu'
    comodo di 600000000000000000000000.

    Il linguaggio C utilizza un formato ben preciso in tal senso, una E -
    maiuscola o minuscola - prima dell'esponente, indicante per l'appunto
    il valore esponenziale, che puo' essere sia positivo sia negativo.  */
    double const avogadro = 6e23;

    /* Nella printf e' possibile utilizzare lo specificatore di conversione
    (conversion specifier) 'e', che stampa un floating point nella forma
    standard */
    printf("%e\n", avogadro);
   
    // Naturalmente anche gli esponenti negativi sono concessi
    float const behemoth = 31337e-3;
    printf("%e\n", behemoth);
    printf("%g\n", behemoth);

    return(EXIT_SUCCESS);
}
