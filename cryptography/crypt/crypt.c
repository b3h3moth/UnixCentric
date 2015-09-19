#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>

#define MAX_STR  256
#define MAX_SALT 12

/* La funzione utilizzata in ambiente UNIX per la cifratura delle password e'
crypt - man 3 crypt - che implementa l'algoritmo di cifratura DES - Data 
Encryption Standard.
*/

int main(int argc, char *argv[]) {
    char password[MAX_STR];
    char salt[MAX_SALT];
    char *pass;

    printf("salt: ");
    scanf("%s", salt);

    printf("password: ");
    scanf("%s", password);
    
    if ((pass = crypt(password, salt)) == NULL) {
        fprintf(stderr, "Err. when (en)crypt password\n");
        exit(EXIT_FAILURE);
    } else
        printf("Encrypt '%s' : %s\n", password, pass);

    return(EXIT_SUCCESS);
}

/*
Compila con: gcc -lcrypt crypt.c
*/
