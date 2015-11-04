#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_SIZE    100

/* Lo scopo del programma e' di crittare una stringa utilizzando una chiave
da 8 bit. */

void xor_char_by_char(char *str, unsigned char key);

int main(void) {
    unsigned short key;         // Chiave di crittazione
    char    string[STR_SIZE];   // Stringa da crittare

    printf("write a text to encrypt: ");
    fgets(string, sizeof(string), stdin);

    printf("write key (integer 1,...,256): ");
    scanf("%hu", &key);
    
    // Una chiave da 8 bit comprende '2^8 -1' chiavi diverse, ovvero 255
    key = (key % 256);

    xor_char_by_char(string, key);
    printf(" encrypted text: %s", string);

    xor_char_by_char(string, key);
    printf("dencrypted text: %s", string);
    
    return(EXIT_SUCCESS);
}

void xor_char_by_char(char *str, unsigned char key) {
    for (int i=0; i<strlen(str); i++)
            str[i] ^= key;

    printf("\n");
}
