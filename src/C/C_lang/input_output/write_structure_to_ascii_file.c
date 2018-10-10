#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_STR 16
#define MAX_BUF 32

struct rec {
    char name[MAX_STR];
    char surname[MAX_STR];
    int  age;
};

typedef struct rec Record;

// The program's purpose is to write a 'Record' structure inside a file (ascii)

int main(void) {
    Record *db;
    FILE *fout, *fin;
    char fname[] = "db.txt";
    char buf[MAX_STR];

    db = malloc(sizeof(Record));
    strcpy(db->name, "Mister");
    db->age = 40;
    strcpy(db->surname, "B3h3m0th");

    // Open an 'ascii' file and then write data
    if ((fout = fopen(fname, "w+")) == NULL) {
        fprintf(stderr, "Err.(%d) fopen(); %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    fprintf(fout, "%s\n%s\n%d\n", db->name, db->surname, db->age);
    fclose(fout);

    // Read data from 'fname'
    if ((fin = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "Err.(%d) fopen(); %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (fgets(buf, MAX_BUF, fin))
        fputs(buf, stdout);

    fclose(fin);

    return(EXIT_SUCCESS);
}
