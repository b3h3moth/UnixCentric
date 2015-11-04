#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE    100

/* Lo scopo del programma e' di cryptare una stringa utilizzando una chiave
da 8 bit. 

Nota: una chiave da 8 bit comprende 2^8 -1 chiavi diverse, ovvero 255.
*/

int encrypt(char *str, unsigned char key);

int main(void) {
    unsigned short key;         // Chiave di crittazione
    char    string[STR_SIZE];   // Stringa da crittare

    printf("write string to encrypt: ");
    fgets(line, sizeof(line), stdin);

    printf("write key: ");
    scanf("%hu", &key);
    
    return(EXIT_SUCCESS);
}

int encrypt(char *str, unsigned char key) {
}
