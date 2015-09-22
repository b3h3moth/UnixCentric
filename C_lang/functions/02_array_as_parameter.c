#include <stdio.h>
#include <stdlib.h>

#define SIZE    10

// Prototipo, l'array sia nel prototipo sia nella dichiarazione della funzione
// e' inserito con l'operatore di subscript [], la lunghezza dello stesso 
// invece non e' invece obbligatoria
int sum(int data[], int length);

int main(void) {
    int my_data[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    // Chiamata della funzione, con l'array - monodimensionale in questo caso.
    // L'operatore di subscript non e' necessario.
    int res = sum(my_data, SIZE);

    printf("Sum is: %d\n", res);

    return(EXIT_SUCCESS);
}

// Somma ciascun elemento dell'array
int sum(int data[], int length) {
    int result = data[0];

    for (int i=0; i<length; i++) 
        result += data[i];

    return result;
}
