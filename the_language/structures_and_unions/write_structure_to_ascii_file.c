#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 16

struct rec {
    char name[MAX_STR];
    char surname[MAX_STR];
    int  age;
};

typedef struct rec Record;

int main(void) {
    Record *db;
    FILE *fout;

    db = malloc(sizeof(Record));
    strcpy(db->name, "Mister");
    db->age = 40;
    strcpy(db->surname, "B3h3m0th");

    // Copy each structure member to file
    if ((fout = fopen("db.txt", "w+"))) {
        fprintf(fout, "%s\n%s\n%d\n", db->name, db->surname, db->age);
        fclose(fout);
    }

    // $ cat db.txt 
    // and reading structure data

    return(EXIT_SUCCESS);
}
