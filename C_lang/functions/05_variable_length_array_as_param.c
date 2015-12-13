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
int sum(int length, int data[length]);

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
