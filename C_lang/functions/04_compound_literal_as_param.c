#include <stdio.h>
#include <stdlib.h>

#define SIZE    10

// Prototipo
int sum(int data[], int length);

/* I letterali composti (compound literals) dal c99 possono essere utilizzati
anche con gli array. Sono array senza identificatore, con il tipo all'interno
di parentesi tonde seguito da parentesi quadre indicanti la dimensione:
(int)[4] ad esempio */

int main(void) {

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
