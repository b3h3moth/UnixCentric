#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *country[] = { "italy", "USA", "Spain", "France", "Germany", "Iran",
        "Denmark", "Russia", "Sweden", "China", "Japan", "Jamaica" };

    /* Talvolta, ad esempio utilizzando la sizeof() per ottenere la lunghezza
    di un vettore, si potrebbe incorrere un un warning del compilatore.
    
    Cio' avviene poiche' sizeof() restituisce un valore di tipo 'size_t',
    ovvero un 'unsigned int', mentre la variabile 'size' e' stata dichiarata di
    tipo 'int'.

    In tal caso e' sufficiente aggiungere un cast che converta l'espressione
    contenente le sizeof() in un 'signed int'  */

    int size = (int)(sizeof(country) / sizeof(country[0]));

    for (int i=0; i<size; i++)
        printf("%s\n", country[i]);

    /* Ancor meglio sarebbe porre il tutto in una macro parametrica:
    #define VECSIZE(x)  ((int)(sizeof(x) / sizeof(x[0])))
    */

    return(EXIT_SUCCESS);
}
