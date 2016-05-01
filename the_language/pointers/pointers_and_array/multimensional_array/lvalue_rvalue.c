#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int matrix[3][4] = { {1,2,3,4},{11,12,13,14},{21,22,23,24} };

    printf("%p\n", (void *)*(matrix + 0));
    printf("%p\n", (void *)matrix);
    printf("%p\n", (void *)&matrix[0][0]);

    *(*(matrix + 1) + 2) = 99;

    for (int i=0; i<3; i++)
        for (int j=0; j<4; j++)
            printf("%d, ", *(*(matrix + i) + j));

    return(EXIT_SUCCESS);
}
