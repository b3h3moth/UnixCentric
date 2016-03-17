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

    if ((fp = fopen(faddrbook, "ab+")) == NULL) {
        fprintf(stderr, "Err. opening file. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ( (option = set_option()) != MENU_OPTIONS) {
        switch (option) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                fputs("Unknow option\n", stdout);
                break;
    }
    return(EXIT_SUCCESS);
}

int set_option(void) {
    int value;
    fputs("[1] save data for printing\n"
          "[2] update an account\n"
          "[3] add a new account\n"
          "[4] delete an account\n"
          "[5] quit\n : ",  stdout);

    return (scanf("%1d", &value));
}
