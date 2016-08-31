#include <stdio.h>
#include <stdlib.h>

/* Lo scopo del programma e' di salvare il valore massimo e il valore minimo di
un vettore di interi, nelle variabili min_value e min_value */

void get_max_min(int vec[], unsigned short size, int *max, int *min);

int main(void) {
    int vec_of_int[] = {98, 42, 54, 60, 70, 68, 11, 76, 54, 12, 98, 76, \
                        99, 40, 84, 56, 23, 31, 24, 49, 73, 51, 43, 20 };
    int max_value, min_value;
    unsigned short vector_size = sizeof(vec_of_int) / sizeof(vec_of_int[0]);

    get_max_min(vec_of_int, vector_size, &max_value, &min_value);

    printf("Largest integer is: %d\n", max_value);
    printf("Smaller integer is: %d\n", min_value);

    return(EXIT_SUCCESS);
}

void get_max_min(int vec[], unsigned short size, int *max, int *min) {
    // Inizializza il massimo e il minimo al primo elemento dell'array
    *max = *min = vec[0];

    for(int i=0; i<size; i++) {
        if (vec[i] > *max)
            *max = vec[i];
        else if (vec[i] < *min)
            *min = vec[i];
    }
}
