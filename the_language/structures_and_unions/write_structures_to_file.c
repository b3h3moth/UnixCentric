#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#define MAX_STR 32

struct rec {
    int id;
    char alias[MAX_STR];
    char email[MAX_STR];
};

typedef struct rec Record;

/* The program's purpose is to write a full structure to a binary file, then
read file and store data within new structure. */

int main(void) {
    Record *address_book, *address_book_backup;
    FILE *fin, *fout;
    char *my_alias = "b3h3m0th";
    char *my_mail = "mymail@email.org";

    // It allocates the proper amount of memory
    address_book = malloc(sizeof(Record));

    // Structure initialization
    address_book->id = 1973;
    strncpy(address_book->alias, my_alias, strlen(my_alias));
    strncpy(address_book->email, my_mail, strlen(my_mail));

    /* Si sta lavorando su un file binario, per cui, per leggerlo, sara'
    necessario utilizzare fread() */
    fout = fopen("fout.txt", "wb");

    if (fout == NULL) {
        fprintf(stderr, "Err.(%d) fopen(out) - %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // write the structure to file and close stream
    fwrite(address_book, sizeof(Record), 1, fout);
    fclose(fout);

    // Read data from file
    address_book_backup = malloc(sizeof(Record));
    fin = fopen("fout.txt", "rb");

    if (fin == NULL) {
        fprintf(stderr, "Err.(%d) fopen(in) - %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    fread(address_book_backup, sizeof(Record), 1, fin);
    fclose(fin);

    printf("   id: %d\n", address_book_backup->id);
    printf("alias: %s\n", address_book_backup->alias);
    printf("email: %s\n", address_book_backup->email);

    return(EXIT_SUCCESS);
}
