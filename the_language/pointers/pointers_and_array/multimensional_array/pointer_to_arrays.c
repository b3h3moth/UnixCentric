#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int matrix[2][2] = { 
        {10,20},
        {30,40}
    };

    // Dichiarazione di un puntatore ad array
    int (*mp)[2] = matrix;

    return(EXIT_SUCCESS);
}
