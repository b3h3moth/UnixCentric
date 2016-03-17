#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LEN 20

enum { MENU_OPTIONS=5 };

struct client_data {
    int id;
    char last_name[MAX_LEN];
    char first_name[MAX_LEN];
    double balance;
};

// Prototipi
int set_option(void);

int main(void) {
    FILE *fp;
    int option;
    char *faddrbook = "addressbook.bin";

    if ((fp = fopen(faddrbook, "rb+")) == NULL) {
        fprintf(stderr, "Err. opening file. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ( (option = set_option()) != MENU_OPTIONS) {
    }
    return(EXIT_SUCCESS);
}

int set_option(void) {
    return 1;
}
