#include <stdio.h>
#include <stdlib.h>

/* Con i vettori a lunghezza variabile (Variable-length array) si puo' 
rendere esplicito il valore che rappresenta l'ampiezza del vettore.

L'ampiezza deve essere dichiarata per prima 'length', e successivamente il 
vettore associato alla propria ampiezza 'data[length]'.

Prototipi equivalenti: 
int sum(int length, int data[*]);
int sum(int length, int data[]);
int sum(int, int [*]);
int sum(int, int []);
*/
int sum(int len, int data[*]);

int main(void) {
    int size;

    printf("Give di size of the array: ");
    scanf("%d", &size);

    // Array a lunghezza varibile
    int vec[size];

    // Inizializza ciascun elemento del vettore con l'indice corrispondente
    for (int i=0; i<size; i++) 
        vec[i] = i;

    // L'invocazione della funzione segue le normali regole
    printf("The sum of each array element is: %d\n", sum(size, vec));
   
    return(EXIT_SUCCESS);
}

// Somma ciascun elemento dell'array
int sum(int len, int data[len]) {
    int result = data[0];

    for (int i=0; i<len; i++) 
        result += data[i];

    return result;
}
