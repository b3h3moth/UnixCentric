#include <stdio.h>
#include <stdlib.h>

#define MAX_STR  256
#define MAX_SALT 12

/* La funzione utilizzata in ambiente UNIX per la cifratura delle password e'
crypt - man 3 crypt - che implementa l'algoritmo di cifratura DES - Data 
Encryption Standard.
*/

int main(int argc, char *argv[]) {
    char password[MAX_STR];
    char salt[MAX_SALT];

    printf("salt: ");
    scanf("%s", salt);

    printf("password: ");
    scanf("%s", password);

    printf("Encrypt '%s' : '%s'\n", password, crypt(password, salt));

    return(EXIT_SUCCESS);
}

/*
Compila con: gcc -lcrypt crypt.c
*/
