#include <stdio.h>
#include <stdlib.h>

// Array length
#define SIZE 10

// Confronto tra puntatori mediante operatori relazionali e di uguaglianza

int main(void) {
    int vec[SIZE] = {98, 16, 24, 10, 87, 28, 93, 11, 54, 92};
    int *pt0 = vec;
    int *pt1 = &vec[5];
    int *pt2 = &vec[SIZE-1];

    printf("Array:\n");
    for (int i=0; i<sizeof(vec)/sizeof(vec[0]); i++)
        printf("[%p] = %d\n", (void *)&vec[i], vec[i]);

    // Il confronto avviene tra indirizzi di memoria (0 false - 1 true)
    printf("Pointer comparison (1 true - 0 false)\n");

    printf("[%p] > [%p] = %d\n", (void *)pt0, (void *)pt1, pt0 > pt1);
    printf("[%p] < [%p] = %d\n", (void *)pt0, (void *)pt1, pt0 < pt1);
    printf("[%p] > [%p] = %d\n", (void *)pt1, (void *)pt2, pt1 > pt2);
    printf("[%p] < [%p] = %d\n", (void *)pt1, (void *)pt2, pt1 < pt2);
    printf("[%p] == [%p] = %d\n", (void *)pt1, (void *)(pt2-2), pt1 < pt2-2);

    // Si usa il tipo di dato _Bool per salvare il risultato del contronto
    _Bool result1 = (pt0 == pt2);
    _Bool result2 = (pt0 < pt1);

    printf("_Bool pt0 == pt2 : %d\n", result1);
    printf("_Bool pt0 <  pt2 : %d\n", result2);

    return(EXIT_SUCCESS);
}
