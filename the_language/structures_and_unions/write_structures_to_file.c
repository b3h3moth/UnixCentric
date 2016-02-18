#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_STR 64

struct rec {
    uint32_t id;
    char alias[MAX_STR];
    char email[MAX_STR];
};

typedef struct rec Record;

/* The program's purpose is to write a full structure to a file */

int main(void) {
    Record *address_book;
    char *my_alias = "b3h3m0th";
    char *my_mail = "b3h3m0th@email.org";

    // It allocates the proper amount of memory
    address_book = malloc(sizeof(Record));

    // Structure initialization
    address_book->id = 1;
    strncpy(address_book->alias, my_alias, strlen(my_alias));
    strncpy(address_book->alias, my_mail, strlen(my_mail));

    return(EXIT_SUCCESS);
}
