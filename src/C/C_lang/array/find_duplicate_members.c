#include <stdio.h>
#include <stdlib.h>

void find_duplicates(int vec[], int size);

/* Lo scopo del programma e' di scrivere una funzione che consenta di trovare
elementi duplicati in un array */

int main(void) {
    int vector[] = {1,12,2,3,4,5,6,7,8,9,10,5,11,12,13,14,15,16,17,15,18,7};

    find_duplicates(vector, sizeof(vector)/sizeof(vector[0]));

    return(EXIT_SUCCESS);
}

void find_duplicates(int vec[], int size) {
    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            if (vec[i] == vec[j]) {
                printf("%d\n", vec[i]);
            }
        }
    }
}
