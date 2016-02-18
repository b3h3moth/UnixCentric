#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#define MAX_STR 32

struct rec {
    char alias[MAX_STR];
    char email[MAX_STR];
};

typedef struct rec Record;

/* The program's purpose is to write a full structure to a file */

int main(void) {
    Record *address_book;
    FILE *fout;
    char *my_alias = "b3h3m0th\0";
    char *my_mail = "mymail@email.org\0";

    // It allocates the proper amount of memory
    address_book = malloc(sizeof(Record));

    // Structure initialization
    strncpy(address_book->alias, my_alias, strlen(my_alias));
    strncpy(address_book->email, my_mail, strlen(my_mail));

    fout = fopen("fout.txt", "w+");

    if (fout == NULL) {
        fprintf(stderr, "Err.(%d) fopen() - %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // write the structure to file
    fwrite(address_book, sizeof(Record), 1, fout);

    fclose(fout);

    return(EXIT_SUCCESS);
}
