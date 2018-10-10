#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_char(void);
void print_short(void);
void print_int(void);
void print_long(void);

/* Just for testing purpose. How to parse command line arguments and compare
them with hypothetical menu items. 

I need a menu', but I don't want getopt() family functions. */

int main(int argc, char *argv[]) {
    char *item_list[] = {"char", "short", "int", "long"};

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <data type>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Verifica se l'argomento corrisponde a una voce del menu'
    for (int i=0; i<sizeof(item_list) / sizeof(item_list[0]); i++) {
        if (strncmp(argv[1], item_list[i], strlen(argv[1])) == 0) {
            printf("found: %s\n", argv[1]);
            break; 
        }
    }

    // Controlla voce per voce
    if (strncmp(argv[1], item_list[0], strlen(argv[1])) == 0) {
        print_char();
    } else if (strncmp(argv[1], item_list[1], strlen(argv[1])) == 0) {
        print_short();
    } else if (strncmp(argv[1], item_list[2], strlen(argv[1])) == 0) {
        print_int();
    } else if (strncmp(argv[1], item_list[3], strlen(argv[1])) == 0) {
        print_long();
    } else {
        printf("item doesn't found\n");
        exit(EXIT_FAILURE);
    }

    printf("body\n");

    return(EXIT_SUCCESS);
}

void print_char(void) {
    fprintf(stdout, "char function\n");
}

void print_short(void) {
    fprintf(stdout, "short function\n");
}

void print_int(void) {
    fprintf(stdout, "int function\n");
}

void print_long(void) {
    fprintf(stdout, "long function\n");
}
