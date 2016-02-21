#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_STR 16

struct rec {
    char name[MAX_STR];
    char surname[MAX_STR];
    int  age;
};

typedef struct rec Record;

// The program's purpose is to write a 'Record' structure inside a file (ascii)

int main(void) {
    Record *db;
    FILE *fout;

    db = malloc(sizeof(Record));
    strcpy(db->name, "Mister");
    db->age = 40;
    strcpy(db->surname, "B3h3m0th");

    // Open an 'ascii' file
    if ((fout = fopen("db.txt", "w+")) == NULL) {
        fprintf(stderr, "Err.(%d) fopen(); %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    fprintf(fout, "%s\n%s\n%d\n", db->name, db->surname, db->age);
    
    fclose(fout);

    // $ cat db.txt 
    // and reading structure data

    return(EXIT_SUCCESS);
}
