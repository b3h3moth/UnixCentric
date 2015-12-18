#include <stdio.h>
#include <stdlib.h>

struct postal_code {
    char *country;
    int code;
};


int main(void) {
    // Inizializzazione del vettore di struttore
    const struct postal_code italia_pc[] = {
        {"Campobasso",  86100},
        {"Roma",    10100},
        {"Torino",  10110}
    };

    return(EXIT_SUCCESS);
}
