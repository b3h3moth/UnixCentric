#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LEN 20

struct client_data {
    int id;
    char last_name[MAX_LEN];
    char first_name[MAX_LEN];
    double balance;
};

// Prototipi

int main(void) {
    FILE *fp;
    int choice;
    char *faddrbook = "addressbook.bin";

    if ((fp = fopen(faddrbook, "rb+")) == NULL) {
        fprintf(stderr, "Err. opening file. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return(EXIT_SUCCESS);
}
