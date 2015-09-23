#include <stdio.h>
#include <stdlib.h>

#define SIZE    5

// Prototipo
int sum(int data[], int length);

/* I letterali composti (compound literals) dal c99 possono essere utilizzati
anche con gli array. Sono array senza identificatore, all'interno di parentesi
tonde vi e' il tipo di dato seguito da parentesi quadre indicanti la 
dimensione */

int main(void) {

    int res = sum( ((int []){10,20,30,40,50}, SIZE );

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
