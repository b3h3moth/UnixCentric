#include <stdio.h>
#include <stdlib.h>
#include <endian.h>

// Prototipo funzione
int little_endian(void);

int main(void) {
    if (little_endian())
        printf("little-endian: %d\n", __LITTLE_ENDIAN);
    else
        printf("big-endian: %d\n", __BIG_ENDIAN);

    return(EXIT_SUCCESS);
}

/* Se il puntatore dereferenziato puntera' ad 1 la macchina avra' una
architettura - ordinamento dei byte nello specifico -, di tipo little-endian, 
big-endian altrimenti */
int little_endian(void) {
    int number_one = 1;
    char *ptr = (char *)&number_one;
    return *ptr;
}

/*
0x00     0x08     0x10     0x18
00000000 00000000 00000000 00000001
ptr -> 0x18 = 1
*/
