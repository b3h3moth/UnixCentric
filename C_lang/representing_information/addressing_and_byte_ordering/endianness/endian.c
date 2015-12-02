#include <stdio.h>
#include <stdlib.h>
#include <endian.h>

// Prototipo funzione
int endian(void);

int main(void) {
    if (endian())
        printf("little-endian: %d\n", __LITTLE_ENDIAN);
    else
        printf("big-endian: %d\n", __BIG_ENDIAN);

    return(EXIT_SUCCESS);
}

/* Se il puntatore dereferenziato puntera' ad 1 la macchina avra' una
architettura - ordinamento dei byte nello specifico -, di tipo little-endian, 
big-endian altrimenti */
int endian(void) {
    int number_one = 1;
    char *ptr = (char *)&number_one;
    return *ptr;
}
