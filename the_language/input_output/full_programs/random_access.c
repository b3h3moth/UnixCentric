#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 20

// Struttura anonima per salvataggio di dati globali, quali il nome del file
struct {
    char *filename;
    FILE *fp;
} global = { .filename = "data.bin", .fp = NULL };

struct date { 
    int day;
    int month;
    int year;
};

typedef struct date Date;

struct rec {
    Date *dt;
    char name[MAX_LEN];
    char email[MAX_LEN];
};

int main(void) {
    return(EXIT_SUCCESS);
}
