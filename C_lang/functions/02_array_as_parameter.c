#include <stdio.h>
#include <stdlib.h>

#define SIZE    10

// Prototipo
int sum(int data[], int length);

int main(void) {
    return(EXIT_SUCCESS);
}

// Somma ciascun elemento dell'array
int sum(int data[], int length) {
    int result = data[0];

    for (int i=0; i<length; i++) 
        result += data[i];

    return result;
}
